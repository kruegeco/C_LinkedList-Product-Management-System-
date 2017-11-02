//Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************
* PROJECT 2-1; Product Management System (Linked List)
* CIS 241 MWF 1000-1050, Fall 2017
* Professor Cao Xiang
* Partners: NONE
* @author Krueger, Cody;
* @version v1.0 01NOV2017 23:30
*
* Description: This is the main file used for the main loop of the
*  program as well as the direction of the user action (via switch).
***********************************************************************/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include "file_utils_LL.h"

//typedef struct product {
//    const char* name;
//    const char* unit;
//    int price;
//    int quantity;
//} node;

// Main Start
int main(int argc, char** argv) {
    // Declare Variables
    /** Holds the size of the file in bytes */
    // int file_size; v2
    /** The character array to hold the contents of the file read */
    // char* buffer; v2

    /** The flag to exit the loop when finished */
    int exit = 0; // Initialized to false

    while (exit==0) {
        int decision = menu();

        switch(decision) {
            case 1:
                _1createList(&head);
                break;
            case 2:
                _2insertItem();
                break;
            case 3:
                _3deleteItem();
                break;
            case 4:
                if (head == NULL) {
                    puts("ERROR: No list has been created");
                }
                else {
                    _4deleteList(head);
                    head = NULL;
                }
                break;
            case 5:
                _5searchList();
                break;
            case 6:
                _6displayList();
                break;
            case 7:
                _7addItem();
                break;
            case 8:
                _8subItem();
                break;
            case 9:
                _9saveList();
                break;
            case 0:
                exit = 1;
                break;
            default:
                break;
        }

    }

    // Free memory when finished
    // free(buffer); v2
    _4deleteList(head);

    // Return error codes FIXME
    return 0;
}



