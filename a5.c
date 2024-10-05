#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "a5.h"

// // Function to find the height of the BST
// int findHeight(struct Node *node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         int leftHeight = findHeight(node->left);
//         int rightHeight = findHeight(node->right);
//         return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
//     }
// }

// // Utility function to print spaces
// void printSpaces(int count)
// {
//     for (int i = 0; i < count; i++)
//     {
//         printf(" ");
//     }
// }

// // Function to print the slashes and backslashes for edges
// void printEdges(struct Node *root, int level, int indentSpace)
// {
//     if (root == NULL)
//     {
//         printSpaces(indentSpace * 2); // Print spaces where a NULL node would be
//         return;
//     }

//     if (level == 1)
//     {
//         // Print slashes (/) for left child and backslashes (\) for right child
//         if (root->left != NULL)
//         {
//             printSpaces(indentSpace / 2 - 1);
//             printf("/");
//             printSpaces(indentSpace / 2 + 1);
//         }
//         else
//         {
//             printSpaces(indentSpace);
//         }
//         if (root->right != NULL)
//         {
//             printf("\\");
//         }
//         else
//         {
//             printSpaces(1);
//         }
//     }
//     else if (level > 1)
//     {
//         // Recursively print edges at the next level
//         printEdges(root->left, level - 1, indentSpace / 2);
//         printEdges(root->right, level - 1, indentSpace / 2);
//     }
// }

// // Function to print nodes at a specific level
// void printLevel(struct Node *root, int level, int indentSpace)
// {
//     if (root == NULL)
//     {
//         printSpaces(indentSpace * 2); // Print spaces where a NULL node would be
//         return;
//     }
//     if (level == 1)
//     {
//         printSpaces(indentSpace); // Leading spaces for current level
//         printf("%d", root->x);    // Print the node value
//         printSpaces(indentSpace); // Trailing spaces
//     }
//     else if (level > 1)
//     {
//         // Print nodes at the next level
//         printLevel(root->left, level - 1, indentSpace / 2);
//         printLevel(root->right, level - 1, indentSpace / 2);
//     }
// }

// // Function to print the BST like a tree with visible edges
// void printTree(struct Node *root)
// {
//     int height = findHeight(root);
//     int indentSpace = pow(2, height); // Determine spacing based on tree height

//     for (int i = 1; i <= height; i++)
//     {
//         // Print nodes at the current level
//         printLevel(root, i, indentSpace);
//         printf("\n");
//         // Print edges (slashes and backslashes) at the next level
//         if (i < height)
//         {
//             printEdges(root, i, indentSpace);
//             printf("\n");
//         }
//     }
// }

// void free_tree(struct Node *root)
// {
//     if (root == NULL) {
//         return;
//     } else {
//     free_tree(root->left);
//     free_tree(root->right);
//     free(root);
//     }
// }

int compareNodes(const void *a, const void *b)
{
    struct Node *node_a = (struct Node *)a;
    struct Node *node_b = (struct Node *)b;
    return (node_a->x - node_b->x);
}

struct Node *build_bst(struct Node *nodes, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct Node * root = &nodes[mid];
    root->left = build_bst(nodes, start, mid - 1);
    root->right = build_bst(nodes, mid + 1, end);
    return root;
}

struct Node * readCoordinates(char *filename, int * node_count)
{

    FILE *fol;
    fol = fopen(filename, "r");
    // testing if the file has successfully opened
    if (fol == NULL)
    {
        return NULL;
    }

    int n = 0;
    char buffer[20];

    // Counting the number of lines
    while (fgets(buffer, sizeof(buffer), fol))
    {
        n++;
    }

    struct Node * nodes = malloc(sizeof(struct Node) * n);
    fseek(fol, 0, SEEK_SET);
    int i = 0;

    // Reading the coordinates and creating nodes
    while (fgets(buffer, sizeof(buffer), fol))
    {
        sscanf(buffer, "%d %d", &(nodes[i].x), &(nodes[i].y));
        (nodes[i]).left = NULL;
        (nodes[i]).right = NULL;
        i++;
    }
    fclose(fol);
    qsort(nodes, n, sizeof(struct Node), compareNodes);
    *node_count = n;
    return nodes;
}

int find_coords(struct Node * bst_root, int coord_x, int coord_y, int radius)
{
    if (bst_root == NULL)
    {
        return 0;
    }

    //printNode(bst_root);
    int x_low = coord_x - radius;
    int x_high = coord_x + radius;
    int x_diff_sq = (bst_root->x - coord_x) * (bst_root->x - coord_x);
    int r_squared = radius * radius;

    if ((bst_root->x <= x_high && bst_root->x >= x_low))
    {
        int y_range = sqrt(r_squared - x_diff_sq);
        int y_high = y_range + coord_y;
        int y_low = coord_y - y_range;
        if (bst_root->y <= y_high && bst_root->y >= y_low)
        {
            //printf("%d %d is within the x range %d:%d and y range %d:%d\n", bst_root->x, bst_root->y, x_low, x_high, y_low, y_high);
            return (1 + find_coords(bst_root->left, coord_x, coord_y, radius) + find_coords(bst_root->right, coord_x, coord_y, radius));
        }
        else
        {
            return (find_coords(bst_root->left, coord_x, coord_y, radius) + find_coords(bst_root->right, coord_x, coord_y, radius));
        }
    }
    else if ((bst_root->x < x_low))
    {
        return find_coords(bst_root->right, coord_x, coord_y, radius);
    }
    else if ((bst_root->x > x_high))
    {
        return find_coords(bst_root->left, coord_x, coord_y, radius);
    }

    return 0;
}

