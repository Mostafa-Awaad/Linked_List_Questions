#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    Node_t *List = NULL;
    uint32_t Choice = 0;
    uint32_t Middle = 0;
    uint32_t Length = 0;
    uint32_t Counter = 0;
    uint32_t Node_No = 0;
    uint32_t Printed_Data = 0;
    uint32_t Num = 0;
    while (1)
    {
        printf("====================================\n");
        printf("-> 1) Insert_Node_At_Beginning\n");
        printf("-> 2) Get_List_Length\n");
        printf("-> 3) Print_Middle_of_linked_list\n");
        printf("-> 4) Reverse Singly Linked List\n");
        printf("-> 5) Display_All_Nodes\n");
        printf("-> 6) Rotate_Singly_Linked_List\n");
        printf("-> 7) Find_Nth_Term From Last Node\n");
        printf("-> 8) Delete_Item_Last_Occur\n");
        printf("-> 9) Exit the Program\n");
        printf("====================================\n");
        printf("Choose the kind of operation on the Linked List: ");
        scanf("%i",&Choice);

        switch (Choice)
        {
            case 1:
                Insert_New_Node_at_Beginning(&List);
                break;
            case 2:
                Length = Get_List_Length (List);
                printf("Current Length of The Linked List: %i\n",Length);
                break;
            case 3:
                Middle = Print_Middle_of_linked_list(List);
                printf("Middle of the Linked List : %i \n",Middle);
                break;
                
            case 4:
                Reverse_Singly_Linked_List(&List);
                break;

            case 5:
                Display_List_Elements(List);
                break;

            case 6:
                printf("print how many nodes you want to rotate: ");
                scanf("%i",&Counter);
                Rotate_Singly_Linked_List(&List, Counter);
                
                break;
            
            case 7:
                printf("Nth Node you want to Print: ");
                scanf("%i",&Node_No);
                Printed_Data= Find_Nth_term(List, Node_No);
                printf("Nth Term = %i \n", Printed_Data);
                break;

            case 8:
                printf("Print the Number to delete its Last occurrence: ");
                scanf("%i",&Num);
                Delete_Last_Occur(&List, Num);
                break;
            case 9:
                exit(1);
                break;
            default:
                printf("Error!! Choice is Out of Range :\n");
                break;
        }
    }
    

    return 0;
}