/*
 * Perspective projection is usually categorized into one-point, two-point and
 * three-point perspective, depending on the orientation of the projection plane
 * towards the axes of the depicted object.
 */

#include <math.h>
#include <stdio.h>
#include <unistd.h>

// screen dimensions
#define WIDTH 160
#define HEIGHT 40

#define CUBE_WIDTH 20
#define HORZ_OFFSET -2 * CUBE_WIDTH

#define INCREMENT 0.6F

#define PROJECTION_CONSTANT 40

float A = 0.0F;
float B = 0.0F;
float C = 0.0F;

typedef struct points3D points3D;
typedef struct points2D points2D;

struct points3D {
  float x;
  float y;
  float z;
};

struct points2D {
  float x;
  float y;
  float z; // depth on 2D
} points2D;

int main() {

  for (;;) {
    printf("\x1b[2J");
    for (float cubeX = -CUBE_WIDTH; cubeX < CUBE_WIDTH; cubeX += INCREMENT) {
      for (float cubeY = -CUBE_WIDTH; cubeY < CUBE_WIDTH; cubeY += INCREMENT) {
      }
    }
    A += 0.05F;
    B += 0.05F;
    C += 0.01F;
  }
  usleep(8000 * 2);
  return 0;
}
