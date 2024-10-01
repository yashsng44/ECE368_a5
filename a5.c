#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>

 int readCoordinates(FILE * fol, int x_2, int y_2, float rad_sq) {
  
  char buffer[10];
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

  return num_match;
}