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

Node * close(Node * head, int target){
    // init
    Node * dummy = malloc(sizeof(*dummy)); // allocating memory for dummy node
    Node * prev = dummy; // setting prev equal to dummy
    Node * curr = head; // setting curr equal to head
    dummy->next = head; // connect dummy to head (on top)

    // finding node
    while(curr != NULL){ // iterating through list
        // check
        if(curr->ID == target){ // node found
            prev->next = curr->next; // connect previous node to the next node
            free(curr); // delete current node
            return dummy->next;
        }

        // iterate
        prev = prev->next; // move previous node by one
        curr = curr->next; // move current node by one
    }

    return head; // node not found (while loop finishes)
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