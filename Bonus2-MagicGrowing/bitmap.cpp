#include "bitmap.h"

#include <assert.h>

#include "BMP.h"

void load_bitmap(const std::string& file, RGBImage& image) {
  BMP bmp(file.c_str());
  unsigned int h = bmp.bmp_info_header.height;
  unsigned int w = bmp.bmp_info_header.width;

  image.resize(h);
  unsigned int idx = 0;
  for (unsigned int i = 0; i < h; ++i) {
    RGBImageRow& row = image[h - 1 - i];
    row.resize(w);
    for (unsigned int j = 0; j < w; ++j) {
      row[j] = {bmp.data[idx], bmp.data[idx + 1], bmp.data[idx + 2]};
      idx += 3;
    }
  }
}

void write_bitmap(const RGBImage& image, const std::string& file) {
  unsigned int width = image.size();
  assert(width > 0);
  unsigned int height = image[0].size();
  assert(height > 0);
  BMP bmp(width, height, false);

  for (unsigned int i = 0; i < height; ++i) {
    for (unsigned int j = 0; j < width; ++j) {
      RGBPixel pixel = image[i][j];
      unsigned int B = std::get<0>(pixel);
      unsigned int G = std::get<1>(pixel);
      unsigned int R = std::get<2>(pixel);
      bmp.set_pixel(j, height - 1 - i, B, G, R, 1.0);
    }
  }

  bmp.write(file.c_str());
}

void rgb2gray(const RGBImage& rgb_image, GrayscaleImage& gray_image) {
  unsigned int width = rgb_image.size();
  assert(width > 0);
  unsigned int height = rgb_image[0].size();
  assert(height > 0);

  gray_image.resize(height);
  for (unsigned int i = 0; i < height; ++i) {
    gray_image[i].resize(width);
    for (unsigned int j = 0; j < width; ++j) {
      RGBPixel rgb_pixel = rgb_image[i][j];
      unsigned int B = std::get<0>(rgb_pixel);
      unsigned int G = std::get<1>(rgb_pixel);
      unsigned int R = std::get<2>(rgb_pixel);

      GrayscalePixel g_pixel = (B + G + R) / 3;
      gray_image[i][j] = g_pixel;
    }
  }
}

void gray2rgb(const GrayscaleImage& gray_image, RGBImage& rgb_image) {
  unsigned int width = gray_image.size();
  assert(width > 0);
  unsigned int height = gray_image[0].size();
  assert(height > 0);

  rgb_image.resize(height);
  for (unsigned int i = 0; i < height; ++i) {
    rgb_image[i].resize(width);
    for (unsigned int j = 0; j < width; ++j) {
      GrayscalePixel g_pixel = gray_image[i][j];
      RGBPixel rgb_pixel = {g_pixel, g_pixel, g_pixel};
      rgb_image[i][j] = rgb_pixel;
    }
  }
}

void mask_rgb_image(const RGBImage& rgb_image, const ImageMask& mask,
                    float alpha, RGBImage& masked_rgb_image) {
  unsigned int width = rgb_image.size();
  assert(width > 0);
  assert(width == mask.size());
  unsigned int height = rgb_image[0].size();
  assert(height > 0);
  assert(height == mask[0].size());
  assert(alpha >= 0.0 && alpha <= 1.0);

  masked_rgb_image.resize(height);
  for (unsigned int i = 0; i < height; ++i) {
    masked_rgb_image[i].resize(width);
    for (unsigned int j = 0; j < width; ++j) {
      RGBPixel rgb_pixel = rgb_image[i][j];
      unsigned int B = std::get<0>(rgb_pixel);
      unsigned int G = std::get<1>(rgb_pixel);
      unsigned int R = std::get<2>(rgb_pixel);
      
      // Make non-selected pixels darker but keep them fully opaque.
      if (!mask[i][j]) {
        B *= alpha;
        G *= alpha;
        R *= alpha;
      }

      masked_rgb_image[i][j] = {B, G, R};
    }
  }
}