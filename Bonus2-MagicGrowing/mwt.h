#pragma once

#include <iostream>
#include <vector>

#include "bitmap.h"

// PRE:  All rows in image have the same size.
//       x and y must be valid indices into image.
// POST: Returns a matrix of bools where every true value corresponds to a pixel
//       with at least one path of T-similar pixels starting at x,y.
ImageMask MWT(const GrayscaleImage& image,
              const unsigned int x, const unsigned int y,
              const unsigned int T);