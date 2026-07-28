/*
 * Perspective projection is usually categorized into one-point, two-point and
 * three-point perspective, depending on the orientation of the projection plane
 * towards the axes of the depicted object.
*/

#include <math.h>
#include <stdio.h>

// screen dimensions
#define WIDTH 160
#define HEIGHT 40

#define CUBE_WIDTH 20
#define HORZ_OFFSET -2 * CUBE_WIDTH

#define INCREMENT 0.6f

#define PROJECTION_CONSTANT 40

typedef struct {
  float x;
  float y;
  float z;
} points3D;

typedef struct {
  float x;
  float y;
} points2D;

int main() {
  for (;;) {
    printf("\x1b[2J");
    for (float cubeX = -CUBE_WIDTH; cubeX < CUBE_WIDTH; cubeX += INCREMENT) {
      for (float cubeY = -CUBE_WIDTH; cubeY < CUBE_WIDTH; cubeY += INCREMENT) {
      }
    }
  }
  return 0;
}
