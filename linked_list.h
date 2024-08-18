#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "platform_types.h"

typedef struct Node
{
    uint32_t Node_Data;
    struct Node *Node_Link;
}Node_t;

typedef struct Node_Double_List
{
    uint32_t Node_Data;
    struct Node *Right_Link_Node;
    struct Node *Left_Link_Node;
}NodeD_t;

void Insert_New_Node_at_Beginning (Node_t **List);
uint32_t Get_List_Length (Node_t *List);
uint32_t Print_Middle_of_linked_list(Node_t *List);
void Reverse_Singly_Linked_List (Node_t **ListHead);
void Display_List_Elements (Node_t *ListHead);
/**
 * @brief  Rotate Single Linked List and Change the List Head or Start Pointer by moving K nodes
 * @param  ListHead  Double Pointer to the List Head --> Double Pointer to change in the content of List Head Pointer
 * @param  K  Variable to Move the List Head K Times
 * @retval  Void Function
 */
void Rotate_Singly_Linked_List (Node_t **ListHead, uint32_t K);
#endif