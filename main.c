#include <math.h>
#include <stdio.h>

/* Perspective projection is usually categorized into one-point, two-point and three-point perspective,
 * depending on the orientation of the projection plane towards the axes of the depicted object.
 */

/*
 * the 3D position of a point A that is to be projected
 */
typedef struct {
  float x;
  float y;
  float z;
} points3D;

// 3D points to be projected onto 2D plane
float A, B, C;
float cubeWidth = 20;

int main() {
  points3D vertices[8] = {{}, {}, {}, {}, {}, {}, {}, {}};
  printf("\x1b[2J");

  return 0;
}
