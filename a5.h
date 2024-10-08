#ifndef a5_h
#define a5_h 
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>

typedef struct Node
{ int x;
  int y;
struct Node *left;
struct Node *right;
} Node;

struct Node * readCoordinates(char * file, int * node_count);
int find_coords(struct Node * root, int x_lower, int x_higher, int radius);
struct Node * build_bst(struct Node * root, int start, int end);
#endif