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
  float rad_sq = radius * radius;

  for(int i = 0; i <= num_coords - 2 ; i = i + 2) {
    float dist = ((coord_arr[i] - x)*(coord_arr[i] - x)) + ((coord_arr[i+1] - y)*(coord_arr[i+1] - y)); 
    if (dist <= rad_sq) {
      num_match++;
    }
  }

  return num_match;
}