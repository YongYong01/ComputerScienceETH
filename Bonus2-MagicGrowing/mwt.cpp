#include "mwt.h"

#include <assert.h>

unsigned int absolute(unsigned int a, unsigned int b){
  if (a > b){
    return a - b;
  }
  else{
    return b - a;
  }
}

// Depth-First Search (DFS) 
void DFS(const GrayscaleImage& image, ImageMask& mask,
         const unsigned int x, const unsigned int y,
         const unsigned int xStart, const unsigned int yStart,
         const unsigned int T) {
  const unsigned int height = image.size();
  const unsigned int width = image.at(0).size();

  if (x >= height || y >= width || x < 0 || y < 0 || mask.at(y).at(x)) {
    return;  // Return if out of bounds or already visited
  }

  if (absolute(image.at(y).at(x), image.at(yStart).at(xStart)) > T) {
    return;  // Return if not similar
  }
  mask.at(y).at(x) = true;

  // Pixel Neighborhood search
  DFS(image, mask, x + 1, y, xStart, yStart, T);
  DFS(image, mask, x - 1, y, xStart, yStart, T);
  DFS(image, mask, x, y + 1, xStart, yStart, T);
  DFS(image, mask, x, y - 1, xStart, yStart, T);
}

// PRE:  All rows in image have the same size.
//       x and y must be valid indices into image.
// POST: Returns a matrix of bools where every true value corresponds to a pixel
//       with at least one path of T-similar pixels starting at x,y.
ImageMask MWT(const GrayscaleImage& image,
              const unsigned int x, const unsigned int y,
              const unsigned int T) {
  
  // get image dimensions
  const unsigned int height = image.size();
  assert(height > 0);
  const unsigned int width = image.at(0).size();

  // init mask
  ImageMask mask(height, ImageMaskRow(width, false));

  // compute mask
  // TODO: implement
  DFS(image, mask, x, y, x, y, T);

  // return mask
  return mask;
}