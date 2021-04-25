#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT 100

double x[COUNT];
double y[COUNT];
int coor_index[COUNT];
double distance[COUNT][COUNT];

void rand_gen(double x[], double y[]) {
  for (int i = 0; i < COUNT; ++i) {
    coor_index[i] = i;
    x[i] = 100.0 * rand() / RAND_MAX;
    y[i] = 100.0 * rand() / RAND_MAX;
  }
}

void euclidian_length(double field[COUNT][COUNT]) {
  for (int j = 0; j < COUNT; ++j)
    for (int k = 0; k < COUNT; ++k)
      field[j][k] = sqrt(pow(x[j] - x[k], 2) + pow(y[j] + y[k], 2));
}

void print_dist() {
  double dist = 0.0;

  for (int i = 0; i < COUNT; ++i) {
    dist += distance[coor_index[i]][coor_index[(i + 1) % COUNT]];
    for (int j = 0; j < COUNT; ++j)
      printf("step (i,j): %d, %d  matrix: %g\n", i, j, distance[i][j]);
  }
  printf("Distance is  %g\n", dist);
}

int main() {
  rand_gen(x, y);
  euclidian_length(distance);
  print_dist();
}
