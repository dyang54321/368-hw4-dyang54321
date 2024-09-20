#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "a4.h"

Node * open(Node * head, int ID){
    // init
    Node * new = malloc(sizeof(*new)); // allocating memory for new node
    new->ID = ID; // initialize new window ID
    new->next = head; // connect new to head (on top)

    // return
    return new; // return new to be set to head
}

#ifdef LIST_PRINT
void listPrint(Node * head){
    if(head != NULL){
        printf("%d\n", head->ID);
    }
}
#endif

#ifdef PRINT_WHOLE
void printWhole(Node * head){
    while(head != NULL) {
        printf("%d\n", head->ID);
        head = head->next;
    }
}
#endif