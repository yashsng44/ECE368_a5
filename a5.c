#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>
#include "a5.h"

bool readCoordinates(char * filename, int ** coord_arr, int * num_coords) {

  FILE *fol;

  fol= fopen(filename, "r");
  // testing if the file has successfully opened
  if (fol == NULL)  
  {
    return false;
  }

  int n = 0;
  char buffer[10];

  while(fgets(buffer, sizeof(buffer), fol)) {
    n++;
  }

  *coord_arr = malloc(sizeof(int)*2*n);
  fseek(fol, 0, SEEK_SET);
  int i = 0;
  
  while(fgets(buffer, sizeof(buffer), fol)) {
    int x, y;
    sscanf(buffer, "%d %d", &x, &y);
    (*coord_arr)[i] = x;
    (*coord_arr)[i+1] = y;
     i += 2;
  }

  *num_coords = n*2;
  fclose(fol);
  return true;
}

int compareCoordinates(int x, int y, int radius, int * coord_arr, int num_coords) {
  int num_match = 0;
  float dist;

  for(int i = 0; i <= num_coords- 2 ; i = i + 2) {
    float var1 = (coord_arr[i] - x)*(coord_arr[i] - x);
    // printf("operation x %d - %d ^ 2 = %d \n", coord_arr[i], x, var1);
    float var2 = (coord_arr[i+1] - y)*(coord_arr[i+1] - y);
    // printf("operation y %d - %d ^ 2 = %d \n", coord_arr[i+1], y, var2);
    dist = sqrt(var1 + var2);
    if (dist <= radius) {
      //printf(" dist %f <= radius %d\n", dist, radius);
      num_match++;
    }
  }
  return num_match;
}