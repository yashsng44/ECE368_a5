#ifndef a5_h
#define a5_h 
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>
#include "a5.h"


bool readCoordinates(char * file_name, int ** coord_arr, int * num_coords);
int compareCoordinates(int coord_x, int coord_y, int radius, int * coord_arr, int num_coords);

#endif