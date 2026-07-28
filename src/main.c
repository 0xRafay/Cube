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

float zBuffer[160 * 44];
char buffer[160 * 44];

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
  float depth;
};

float calculateX(float i, float j, float k) {
  return ((j * sinf(A)) * (sinf(B) * cosf(C))) -
         ((k * cosf(A)) * (sinf(B) * cosf(C))) + ((j * cosf(A)) * sinf(C)) +
         ((k * sinf(A)) * sinf(C)) + ((i * cosf(B)) * cosf(C));
}

float calculateY(float i, float j, float k) {
  return ((j * cosf(A)) * cosf(C)) + ((k * sinf(A)) * cosf(C)) -
         ((j * sinf(A)) * (sinf(B) * sinf(C))) +
         ((k * cosf(A)) * (sinf(B) * sinf(C))) - ((i * cosf(B)) * sinf(C));
}

float calculateZ(float i, float j, float k) {
  return ((k * cosf(A)) * cosf(B)) - ((j * sinf(A)) * cosf(B)) + (i * sinf(B));
}

points2D projectionOnSurface(float cubeX, float cubeY, float cubeZ, int ch) {

  points3D cube = {cubeX, cubeY, cubeZ};
  points2D projected = {};
  points3D rotated = {};

  rotated.x = calculateX(cubeX, cubeY, cubeZ);
  rotated.y = calculateY(cubeX, cubeY, cubeZ);
  rotated.z = calculateZ(cubeX, cubeY, cubeZ);

  float ooz = 1.0F / rotated.z;

  projected.x =
      (WIDTH / 2.0F) + (HORZ_OFFSET) + (PROJECTION_CONSTANT * rotated.x * ooz);
  projected.y = (HEIGHT / 2.0F) + (PROJECTION_CONSTANT * rotated.y * ooz);

  int idx = ((int)(projected.x) + ((int)projected.y * WIDTH));
  if (idx >= 0 && idx < WIDTH * HEIGHT) {
    if (ooz > zBuffer[idx]) {
      zBuffer[idx] = ooz;
      buffer[idx] = (char)ch;
    }
  }
  return projected;
}

int main() {

  for (;;) {
    printf("\x1b[2J");
    for (float cubeX = -CUBE_WIDTH; cubeX < CUBE_WIDTH; cubeX += INCREMENT) {
      for (float cubeY = -CUBE_WIDTH; cubeY < CUBE_WIDTH; cubeY += INCREMENT) {
        projectionOnSurface(cubeX, cubeY, CUBE_WIDTH, '@');
      }
    }
    A += 0.05F;
    B += 0.05F;
    C += 0.01F;
  }
  usleep(8000 * 2);
  return 0;
}
