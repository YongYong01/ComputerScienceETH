#pragma once

#include <string>
#include <tuple>
#include <vector>

using RGBPixel = std::tuple<unsigned int, unsigned int, unsigned int>;
using RGBImageRow = std::vector<RGBPixel>;
using RGBImage = std::vector<RGBImageRow>;

using GrayscalePixel = unsigned int;
using GrayscaleImageRow = std::vector<GrayscalePixel>;
using GrayscaleImage = std::vector<GrayscaleImageRow>;

using ImageMaskRow = std::vector<bool>;
using ImageMask = std::vector<ImageMaskRow>;

void load_bitmap(const std::string& file, RGBImage& image);

void write_bitmap(const RGBImage& image, const std::string& file);

void rgb2gray(const RGBImage& rgb_image, GrayscaleImage& gray_image);
void gray2rgb(const GrayscaleImage& gray_image, RGBImage& rgb_image);

void mask_rgb_image(const RGBImage& rgb_image, const ImageMask& mask,
                    float alpha, RGBImage& masked_rgb_image);