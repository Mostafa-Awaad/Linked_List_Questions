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

/**
 * @brief  Finds the N-th term from the end of a singly linked list.
 * 
 * This function calculates the position of the N-th node from the end of a given
 * singly linked list and returns its data. If the list is empty, the function returns 0.
 * 
 * @param  ListHead  A pointer to the head of the singly linked list.
 * @param  N         The position from the end of the list whose data is to be retrieved.
 *                   It is expected that 1 <= N <= length of the list.
 * 
 * @retval  uint32_t  The data of the N-th node from the end of the list.
 *                   If the list is empty, the function returns 0.
 * 
 */
sint32_t Find_Nth_term (Node_t *ListHead, uint32_t N);

/**
 * @brief  Delete last occurrence of an item from linked list
 * @param  ListHead  Double Pointer to the List Head --> Double Pointer to change in the content of List Head Pointer in case of first node
 * @param  Num  Item to search about its last occurrence
 * @retval  Void Function
 */
void Delete_Last_Occur (Node_t **ListHead, uint32_t Num);
#endif