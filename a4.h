#ifndef A4_H
#define A4_H
#include <stdlib.h>

typedef struct Node {
    int window;
    struct Node * next;
} Node;

void open(Node * head, int window);
void close();
void swap();
void listPrint(Node * head);

#endif