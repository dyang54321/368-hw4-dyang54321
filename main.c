#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

int main(void){
    // init
    Node * head = malloc(sizeof(Node)); // allocating memory for head
    char * initc = malloc(sizeof(*initc)); // allocating memory for initial command
    int initID; // initial window ID
    scanf("%s %d", initc, &initID); // scanning initial command/ID

    // command logic
    if(!strcmp(initc, "open")){ // if initial command is open
        head->ID = initID; // initialize value
        head->next = NULL; // connect next
    }

    else{ // if initial command is not open then close
        free(head); // free head
    }

    free(initc); // free initial command

#ifdef LIST_PRINT
    listPrint(head); // print head
#endif

    // window list
    while(head != NULL){ // while the list is not empty
        // setup
        char * command = malloc(sizeof(*command)); // allocation for command string
        int ID; // window value
        scanf("%s %d", command, &ID); // scanning command and window id

        // command logic
        if(!strcmp(command, "open")){
            head = open(head, ID); // enqueue ID and set head
        }

#ifdef LIST_PRINT
        // print
        listPrint(head); // print head
#endif

#ifdef PRINT_WHOLE
        printWhole(head);
#endif

        free(command); // freeing input string
    }
}