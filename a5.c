#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <math.h>
#include "a5.h"

struct Node newNode(int x, int y) {
  struct Node node;
  node.x = x;
  node.y = y;
  node.left = NULL;
  node.right = NULL;
  return node;
}

int compareNodes(const void *a, const void *b) {
  struct Node * node_a = (struct Node *)a;
  struct Node * node_b = (struct Node *)b;
  return (node_a->x - node_b->x);
}

void printNodes(struct Node * nodes, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        printf("| %d |->", nodes[i].x);
    }
    printf("NULL\n");
}

struct Node * build_bst(struct Node * nodes, int start, int end) {
  if (start > end) {
    return NULL;
  }
  int mid = (start + end)/2;
  struct Node * root = &nodes[mid];
  root->left = build_bst(nodes, start, mid - 1);
  root->right = build_bst(nodes, mid + 1, end);
  return root;
  }

struct Node* readCoordinates(char * filename) {
  
  FILE *fol;
  fol= fopen(filename, "r");
  // testing if the file has successfully opened
  if (fol == NULL)  
  {
    return NULL;
  }

  int n = 0;
  char buffer[10];

  while(fgets(buffer, sizeof(buffer), fol)) {
    n++;
  }

  struct Node * nodes = malloc(sizeof(struct Node) * n);
  fseek(fol, 0, SEEK_SET);
  int i = 0;
  
  while(fgets(buffer, sizeof(buffer), fol)) {
    int x, y;
    sscanf(buffer, "%d %d", &x, &y);
    nodes[i] = newNode(x, y);
    i++;
  }
  fclose(fol);
  qsort(nodes, n, sizeof(struct Node), compareNodes);
  printNodes(nodes, n);
  struct Node *root = build_bst(nodes, 0, n - 1);
  return root;
}

int find_coords(struct Node * bst_root, int coord_x, int coord_y, int radius) {
  if (bst_root == NULL) {
    return 0;
  }
  
  int x_low = coord_x - radius;
  int x_high = coord_x + radius;
  printf("%d\n", bst_root->x);
  if (bst_root->x <= x_high && bst_root->x >= x_low) {
    printf("%d\n", bst_root->x);
    int y_range = sqrt(radius*radius - (bst_root->x - coord_x)*(bst_root->x - coord_x));
    int y_high = y_range + coord_y;
    int y_low = coord_y - y_range;
    if (bst_root->y <= y_high && bst_root->y >= y_low) {
    return (1 + find_coords(bst_root->left, coord_x, coord_y, radius) + find_coords(bst_root->right, coord_x, coord_y, radius));
    } else if (bst_root->x < x_low) {
        return find_coords(bst_root->right, coord_x, coord_y, radius);
    } else if (bst_root->x > x_high) {
        return find_coords(bst_root->left, coord_x, coord_y, radius);
    }
  }
    return 0;
}





