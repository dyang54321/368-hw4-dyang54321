#ifndef A4_H
#define A4_H
#include <stdlib.h>

typedef struct Node {
    int ID; // window ID    
    struct Node * next; // next node
} Node;

Node * open(Node * head, int window);
Node * close(Node * head, int target);
void listPrint(Node * head);
void printWhole(Node * head);
void swap();


#endif