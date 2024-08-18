#include "linked_list.h"

void Insert_New_Node_at_Beginning (Node_t **List)
{
    Node_t *New_Node = NULL;
    if (NULL == List)
    {
        printf("Error!! due to passing a NUll pointer \n");
    }
    else
    {
        New_Node = (Node_t*)malloc(sizeof(Node_t));
        if (NULL != New_Node)
        {
            printf("Enter the data you want to insert: ");
            scanf("%i",&(New_Node->Node_Data));
            /* Check if the linked list is empty */
            if (NULL == *List)
            {
                *List =  New_Node;
                New_Node->Node_Link = NULL;
                
            }
            else
            {
                New_Node->Node_Link = *List;
                *List = New_Node;
            }
            
        }
        else{/* Nothing */}
    }

}
uint32_t Get_List_Length (Node_t *List)
{
    uint32_t Counter = 1;
    Node_t *Temp_Node = NULL;

    /* check if the Linked List is empty */
    if (NULL == List)
    {
        Counter = 0;
    }
    else
    {
        Temp_Node = List;
        while (Temp_Node->Node_Link != NULL)
        {
            Temp_Node = Temp_Node->Node_Link;
            Counter++;
        }
    }
    return Counter;
}
uint32_t Print_Middle_of_linked_list(Node_t *List)
{
    Node_t *Node_List_Counter = NULL;
    uint32_t Arr_index = 0;
    uint32_t List_Length = Get_List_Length(List);
    uint32_t Arr_Data[List_Length];
    uint32_t Middle = 0;

    if (NULL == List)
    {
        printf("Error!! The Linked List is Empty \n");
    }
    else
    {
        Node_List_Counter = List;
        while (Node_List_Counter->Node_Link != NULL)
        {
            Arr_Data[Arr_index] = Node_List_Counter->Node_Data;
            Node_List_Counter = Node_List_Counter->Node_Link;
            Arr_index++;
        }
        Middle = Arr_Data[List_Length/2];
    }
    
    return Middle;
}

void Reverse_Singly_Linked_List (Node_t **ListHead)
{
    Node_t *Previous = NULL;
    Node_t *Current  = *ListHead;
    Node_t *Next = NULL;

    while ( NULL != Current)
    {
        Next = Current->Node_Link;
        Current->Node_Link = Previous;
        Previous = Current;
        Current = Next;
    }
    *ListHead = Previous;
}


void Display_List_Elements (Node_t *ListHead)
{
    Node_t *Temp_Node = NULL;
    Temp_Node = ListHead;
    if (NULL == ListHead)
    {
        printf("Error !! The memory block you have passed is Empty !!\n");
    }
    while (NULL != Temp_Node)
    {
        printf("%i -> ",Temp_Node->Node_Data);
        Temp_Node = Temp_Node->Node_Link;
    }
    if (Temp_Node == NULL)
    {
        printf("NULL");
    }
    printf("\n");
}



/**
 * @brief  Rotate Single Linked List and Change the List Head or Start Pointer by moving K nodes
 * @param  ListHead  Double Pointer to the List Head --> Double Pointer to change in the content of List Head Pointer
 * @param  K  Variable to Move the List Head K Times
 * @retval  Void Function
 */
void Rotate_Singly_Linked_List (Node_t **ListHead, uint32_t K)
{
    uint32_t List_Length = Get_List_Length(*ListHead);
    uint32_t Counter = K;
    /* Make Circular Singly_Linked_List */
    Node_t *Node_List_Counter = *ListHead;
    Node_t *Temp_Node = *ListHead;
    /* Reach to the Last Node */
    while (NULL != Node_List_Counter->Node_Link)
    {
        Node_List_Counter = Node_List_Counter->Node_Link;
    }
    /* Linking the Last Node with with the First Node */
    Node_List_Counter->Node_Link = *ListHead;
    
    /* Check if the K or the number of List Head moves is less than the List Length */
    if (K < List_Length)
    {
        /* Looping Until the New ListHead */
        while (K--)
        {
            (*ListHead) = Temp_Node->Node_Link;
            Temp_Node = Temp_Node->Node_Link;
        }    
    }
    /* K is equal or greater than List Length */
    else
    {
        printf(" Invalid K Value you Cannot Rotate %i Times \n",K);
    }
    /* Change the Last Node Position to Solve the problem of infinite loop */
    while (Counter--)
    {
        Node_List_Counter = Node_List_Counter->Node_Link;
    }
    Node_List_Counter->Node_Link = NULL;
}