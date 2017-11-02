//Number of allowed character for dev reference (line below)
//1234567890123456789012345678901234567890123456789012345678901234567890
/***********************************************************************
* PROJECT 2-2a; Product Management System (Linked List)
* CIS 241 MWF 1000-1050, Fall 2017
* Professor Cao Xiang
* Partners: NONE
* @author Krueger, Cody;
* @version v1.0 01NOV2017 23:30
*
* Description: This is the header file used to declare the functions for
*  file_utils_LL.c used in C_LL.
***********************************************************************/

#ifndef _C_LINKEDLIST_FILE_UTILS_LL_H_
#define _C_LINKEDLIST_FILE_UTILS_LL_H_
// previous functions
//int write_file( char* filename, char *buffer, int size);

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
void _1createList (node** phead);
void _2insertItem ();
int _3deleteItem ();
void _4deleteList (node* tHead);
int _5searchList ();
void _6displayList ();
int _7addItem ();
int _8subItem ();
int _9saveList ();
int _0exit ();

#endif //_C_LINKEDLIST_FILE_UTILS_LL_H_
