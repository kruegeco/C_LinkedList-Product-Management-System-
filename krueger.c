//Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************
* PROJECT 2-1; Product Management System (Linked List)
* CIS 241 MWF 1000-1050, Fall 2017
* Professor Cao, Xiang
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
#include <string.h>
//#include "file_utils_LL.h"

//typedef struct product {
//    const char* name;
//    const char* unit;
//    int price;
//    int quantity;
//} node;

// new functions
typedef struct product {
    struct product* link;
    const char* name;
    const char* unit;
    int price;
    int quantity;
} node;

// declare variables
node* head = NULL;
node* beforeTemp = NULL;
node* temp = NULL;

int menu();
void _1createList (node** pHead);
void _2insertItem ();
int _3deleteItem ();
void _4deleteList (node* tHead);
int _5searchList ();
void _6displayList ();
int _7addItem ();
int _8subItem ();
int _9saveList ();

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

int menu() {
    puts(
            "1: Create an empty list     2: Insert a product\n"
                    "3: Delete a product         4: Delete the entire list\n"
                    "5: Search a product         6: Display products in the list\n"
                    "7: Purchase a product       8: Sell a product\n"
                    "9: Save to file             0: Exit");
    int choice;
    scanf("%d", &choice);
    return choice;
};

void _1createList (node** pHead) {
    if (*pHead==NULL) {
        *pHead = (node*)malloc(sizeof(node));
        head->link = NULL;
        head->name = "";
        head->unit = "";
        head->price = 0;
        head->quantity = 0;
        puts("Empty list successfully created");
    } else
        puts("ERROR: There is already a linked list created!");
};

void _2insertItem () {
    if (head == NULL) {
        puts("ERROR: No list has been created");
    }
    else if (_5searchList()==0) {
        puts("Please enter product info delimited by spaces-\n"
                     "\tformat: name unit price quantity; str str int int ");
        node* first = (node*)malloc(sizeof(node)); // Create first and insert at head
        first->link = head->link;
        first->name = (char*)malloc(10*sizeof(char));
        first->unit = (char*)malloc(10*sizeof(char));
        head = first;
        scanf("%s %s %d %d", first->name, first->unit, &first->price, &first->quantity);
        while (first->price <= 0 || first->quantity <= 0) {
            puts("ERROR! Price and quantity must be greater than 0, please re-enter price and quantity!");
            puts("\tFormat: price quantity; int int ");
            scanf("%d %d", &first->price, &first->quantity);
        }
    } else
        puts("ERROR: This item already exists in the list!");
}

int _3deleteItem () {
    if (head == NULL) {
        puts("ERROR: No list has been created");
        return 0;
    }
    else if (_5searchList()==1) {
        beforeTemp->link = temp->link->link; // FIXME Does this change the data of the pointer?
        free(temp->name);
        free(temp->unit);
        free(temp);
        puts("Item deleted");
        return 1;
    } else
        puts("No item deleted");
    return 0;
};

void _4deleteList(node* tHead) {
    if (tHead != NULL) {
        _4deleteList(tHead->link);
        free(temp->name);
        free(temp->unit);
        free(tHead);
    }
};

int _5searchList() {
    if (head == NULL) {
        puts("ERROR: No list has been created");
        return 0;
    } else {
        beforeTemp = head;
        temp = head->link;
        puts("Please enter the name of the product:");
        char* target = (char*)malloc(10*sizeof(char));
        scanf("%s", target);
        while(temp!=NULL){
            if (strcmp(temp->name, target) == 0) {
                puts("Item found");
                free(target);
                return 1; // true
            }
            beforeTemp = temp;
            temp=temp->link;
        }
        puts("Item not found");
        free(target);
        return 0; // false
    }
};

void _6displayList () {
    if (head == NULL) {
        puts("ERROR: No list has been created");
        return;
    } else {
        temp = head->link;

        while(temp!=NULL){
            puts("-Product Information-");
            printf("Name: %s", temp->name);
            printf("Unit: %s", temp->unit);
            printf("Price: %d", temp->price);
            printf("Quantity: %d\n", temp->quantity);
            temp=temp->link;
        }
    }
};

int _7addItem () {
    if (head == NULL) {
        puts("ERROR: No list has been created");
        return 0;
    }
    else if (_5searchList()==1) {
        puts("Please enter amount to purchase:");
        int add;
        scanf("%d", &add);
        while (add < 0) {
            puts("ERROR! Quantity must be non-negative, please re-enter quantity!");
            puts("\tFormat: quantity; int ");
            scanf("%d", &add);
        }
        temp->quantity += add;
        return 1;
    }
    else
        return 0;
};

int _8subItem () {
    if (head == NULL) {
        puts("ERROR: No list has been created");
        return 0;
    }
    else if (_5searchList()==1) {
        puts("Please enter amount to sell:");
        int sub;
        scanf("%d", &sub);
        while (sub < 0 && sub > temp->quantity) {
            puts("ERROR! Quantity must be non-negative, and no more than what is in stock, please re-enter quantity!");
            puts("\tFormat: quantity; int ");
            printf("Current quantity: %d\n", temp->quantity);
            scanf("%d", &sub);
        }
        temp->quantity -= sub;
        if (temp->quantity <= 0) {
            beforeTemp->link = temp->link->link; // FIXME Does this change the data of the pointer?
            free(temp);
        }
        return 1;
    }
    else
        return 0;
};

int _9saveList () {

    if (head == NULL) {
        puts("ERROR: No list has been created");
        return 0;
    } else {
        FILE* pSF; // pointer to Save File
        pSF = fopen ("LinkedList.txt", "w");

        temp = head->link;

        fprintf(pSF, "-Product Information-\n");

        while(temp!=NULL){
            fprintf(pSF, "%s %s %d %d\n", temp->name, temp->unit, temp->price, temp->quantity);
            temp=temp->link;
        }

        fclose(pSF);
        return 1;
    }
};



