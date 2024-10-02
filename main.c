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

int coord_x, coord_y, radius, num_coords = 0;
// int * coord_arr_x, coord_arr_y;
struct Node * root = readCoordinates(argv[1]);

while(scanf("%d %d %d", &coord_x, &coord_y, &radius) == 3) {
num_coords = find_coords(root, coord_x, coord_y, radius);
printf("%d\n", num_coords);
}

return EXIT_SUCCESS;
}
    

