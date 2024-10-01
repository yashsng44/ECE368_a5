#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>
#include "a5.h"

int main(int argc, char ** argv) {

if (argc != 2)
    {
      return EXIT_FAILURE;
}

int coord_x, coord_y, radius = 0;
FILE *fol;
fol= fopen(argv[1], "r");

if (fol == NULL)  
{
    return false;
}

while(scanf("%d %d %d", &coord_x, &coord_y, &radius) == 3) {
  fseek(fol, 0, SEEK_SET);
  float rad_sq = radius * radius;
  printf("%d\n", readCoordinates(fol,  coord_x, coord_y, rad_sq));
}

fclose(fol);
return EXIT_SUCCESS;
}
    

