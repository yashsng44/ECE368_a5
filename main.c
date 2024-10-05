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
int node_count;
struct Node * node_arr = readCoordinates(argv[1], &node_count);
struct Node * bst_root = build_bst(node_arr, 0, node_count - 1);
//printTree(bst_root);
 while(scanf("\n%d %d %d", &coord_x, &coord_y, &radius) == 3) {
  num_coords = find_coords(bst_root, coord_x, coord_y, radius); // what about for the case where radius = 0???
  printf("%d\n", num_coords);
}

free(node_arr);
//free(bst_root);

return EXIT_SUCCESS;
}
    

