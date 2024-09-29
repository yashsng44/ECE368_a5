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

while(scanf("%d %d %d", &coord_x, &coord_y, &radius) == 3) {
printf("%d\n", readCoordinates(argv[1],  coord_x, coord_y, radius));
}

return EXIT_SUCCESS;
}
    

