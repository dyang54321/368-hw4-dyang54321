#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a4.h"

int main(void){
    // init
    Node * head = malloc(sizeof(Node)); // allocating memory for head
    char * initc = malloc(sizeof(char*)); // allocating memory for initial command
    int initID; // initial window ID
    scanf("%s %d", initc, &initID); // scanning initial command/ID
    int found; // node found or not in close function

    // command logic
    if(initc[0] == 'o'){ // if initial command is open
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
        char * command = malloc(sizeof(char*)); // allocation for command string
        int ID; // window value
        scanf("%s %d", command, &ID); // scanning command and window id

        // command logic
#ifdef OPEN
        if(command[0] == 'o'){ // open
            head = open(head, ID); // enqueue ID and set head
        }
#endif

#ifdef CLOSE
        else if(command[0] == 'c'){ // close
            head = close(head, ID, &found); // remove window ID and set head
        }
#endif 

#ifdef SWITCH
        else{ // switch (assumming all inputs are valid)
            head = swap(head, ID); // swapping window ID to front and set head
        }
#endif

#ifdef LIST_PRINT
        // print
        listPrint(head); // print head
#endif

#ifdef PRINT_WHOLE
        printWhole(head); // print whole
#endif

        free(command); // freeing input string
    }
}