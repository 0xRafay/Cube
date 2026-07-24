#include <math.h>
#include <stdio.h>

/* Perspective projection is usually categorized into one-point, two-point and
 * three-point perspective, depending on the orientation of the projection plane
 * towards the axes of the depicted object.
 */

/*
 * the 3D position of a point A that is to be projected
 */

#define FOCAL_LENGTH 200

typedef struct {
  float x;
  float y;
  float z;
} points3D;

typedef struct {
  float x;
  float y;
} points2D;

// 3D points to be projected onto 2D plane
float A, B, C;
float cubeWidth = 20;

int main() {
  // 3d points i defined
  points3D vertices3D[8] = {
      {-10, 10, 20}, {10, 10, 20}, {10, -10, 20}, {-10, -10, 20},

      {-10, 10, 40}, {10, 10, 40}, {10, -10, 40}, {-10, -10, 40}};

  // the 3d points are converted to a 2d plane
  points2D vertices2D[] = {};

  float centerX = 40;
  float centerY = 12;

  float screenX;
  float screenY;

  // this is the projection math
  for (int i = 0; i < 8; i++) {
    screenX = (((vertices3D[i].x) * FOCAL_LENGTH) / vertices3D[i].z) + centerX;
    vertices2D[i].x = screenX;

    screenY =
        (((centerY - (vertices3D[i].y)) * FOCAL_LENGTH) / vertices3D[i].z);

    vertices2D[i].y = screenY;
  }

  for (;;) {
    printf("\x1b[2J");
  }
  printf("");

  return 0;
}
