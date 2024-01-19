#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "bitmap.h"
#include "mwt.h"

// helper function to load original input image
void load_input_image(RGBImage& img) {
  std::cout << "Select an image: ";
  std::string img_name;
  std::cin >> img_name;

  load_bitmap("imgs/" + img_name + ".bmp", img);
}

// helper function to write output image
void write_output_image(RGBImage& original_image,
                        ImageMask mask, unsigned int x,
                        unsigned int y, unsigned int bbx0, unsigned int bbx1,
                        unsigned int bby0, unsigned int bby1) {
  // combine original image with computed mask
  RGBImage output_image;
  mask_rgb_image(original_image, mask, 0.33, output_image);

  // mark selected pixel
  for (int i = -2; i < 3; ++i) {
    int _y = static_cast<int>(y) + i;
    if (_y < 0 || _y >= static_cast<int>(output_image.size())) continue;
    RGBImageRow& output_row = output_image.at(_y);
    for (int j = -2; j < 3; ++j) {
      int _x = static_cast<int>(x) + j;
      if (_x < 0 || _x >= static_cast<int>(output_row.size())) continue;
      output_row[_x] = {0, 0, 255};
    }
  }

  // draw bounding box
  for (unsigned int j = bbx0; j < bbx1; ++j) {
    output_image.at(bby0).at(j) = {0, 255, 0};
    output_image.at(bby1).at(j) = {0, 255, 0};
  }
  for (unsigned int i = bby0; i < bby1; ++i) {
    output_image.at(i).at(bbx0) = {0, 255, 0};
    output_image.at(i).at(bbx1) = {0, 255, 0};
  }

  // write image
  write_bitmap(output_image, "./cx_out/output.bmp");
}

int main() {
  // load input image
  RGBImage rbg_image;
  load_input_image(rbg_image);
  unsigned int height = rbg_image.size();
  unsigned int width = rbg_image[0].size();

  // get selected pixel
  std::cout << "Select a pixel (x y) and a threshold (T): ";
  unsigned int x, y, t;
  std::cin >> x >> y >> t;

  // convert to grayscale and run MWT
  GrayscaleImage gray_image;
  rgb2gray(rbg_image, gray_image);
  ImageMask mask = MWT(gray_image, x, y, t);

  // compute number of selected pixels and bounding box
  assert(mask.size() == height && mask[0].size() == width);
  unsigned int n_selected_pixels = 0;
  unsigned int bbx0 = width, bby0 = height;
  unsigned int bbx1 = 0, bby1 = 0;
  for (unsigned int i = 0; i < height; ++i) {
    ImageMaskRow& row = mask.at(i);
    for (unsigned int j = 0; j < width; ++j) {
      if (row.at(j)) {
        // count pixel
        n_selected_pixels += 1;

        // update bounding box
        bbx0 = std::min(j, bbx0);
        bbx1 = std::max(j, bbx1);
        bby0 = std::min(i, bby0);
        bby1 = std::max(i, bby1);
      }
    }
  }
  std::cout << "Number of selected pixels: " << n_selected_pixels << std::endl;
  std::cout << "Bounding box (" 
            << bbx0 << ", " << bby0 << ", " << bbx1 << ", " << bby1 
            << ")" << std::endl;

  // save output image
  write_output_image(rbg_image, mask, x, y, bbx0, bbx1, bby0, bby1);

  return 0;
}
