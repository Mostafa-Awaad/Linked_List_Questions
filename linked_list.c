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
    if (NULL != (*ListHead))
    {
        uint32_t List_Length = Get_List_Length(*ListHead);
        uint32_t Counter = K;
        /* Make Circular Singly_Linked_List */
        Node_t *Current = *ListHead;
        Node_t *Temp_Node = *ListHead;
        /* Reach to the Last Node */
        while (NULL != Current->Node_Link)
        {
            Current = Current->Node_Link;
        }
        /* Linking the Last Node with with the First Node */
        Current->Node_Link = *ListHead;
        
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
            Current = Current->Node_Link;
        }
        Current->Node_Link = NULL;
    }
    else
    {
        printf("Error !! The List is empty !!\n");
    }
    
}

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
 * @note   The function assumes that N is a valid position within the list (i.e., 
 *         N should not be greater than the length of the list). If N is greater
 *         than the list length, the behavior is undefined.
 */
sint32_t Find_Nth_term (Node_t *ListHead, uint32_t N)
{
    return_status_t ret_status = R_NOK;
    uint32_t List_Length = Get_List_Length(ListHead);
    uint32_t Nth_term = 1;  // Initialize N-th term with a default value (1)
    if (N <= List_Length)
    {
        ret_status = R_OK;
        
        Node_t *Node_List_Counter = ListHead;  // Pointer to traverse the list

        if (NULL != ListHead)  // Check if the list is not empty
        {
            /* Modify the N to be able to reach the Target Node from the List Head */
            N = (List_Length - N) + 1;

            // Traverse the list until reaching the target node
            while (N>1)
            {
                Node_List_Counter = Node_List_Counter->Node_Link;
                N--;
            }
            // Store the data of the target node in Nth_term
            Nth_term = Node_List_Counter->Node_Data;
        }
        else
        {
            // If the list is empty, set Nth_term to 0
            Nth_term = 0;
        }
    
    }
    else
    {
        printf("Undefined behaviour!! You entered value greater than List Length\n");
        
        Nth_term = -1;
    }
    return Nth_term;
}