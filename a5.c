#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>
#include "a5.h"

 int readCoordinates(char * filename, int x_2, int y_2, int radius) {

  FILE *fol;

  fol= fopen(filename, "r");
  // testing if the file has successfully opened
  if (fol == NULL)  
  {
    return false;
  }

  char buffer[10];
  float rad_sq = radius*radius;
  fseek(fol, 0, SEEK_SET);
  int num_match = 0;
  while(fgets(buffer, sizeof(buffer), fol)) {
    int x, y;
    sscanf(buffer, "%d %d", &x, &y);
    float dist = ((x - x_2)*(x - x_2)) + ((y - y_2)*(y - y_2)); 
    if (dist <= rad_sq) {
      num_match++;
    }
  }

  fclose(fol);
  return num_match;
}