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

int * coord_arr;
bool rtv;
int num_coords;
rtv = readCoordinates(argv[1], &coord_arr, &num_coords);
if (rtv == false){
  return EXIT_FAILURE;
}

int coord_x, coord_y, radius = 0;

while(1) {
scanf("%d %d %d", &coord_x, &coord_y, &radius);
printf("%d\n", compareCoordinates(coord_x, coord_y, radius, coord_arr, num_coords));
if (radius == 4) {
    free(coord_arr);
    return EXIT_SUCCESS;
}
}

free(coord_arr);
return EXIT_SUCCESS;
}
    

