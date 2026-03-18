#include <stdio.h>
#include<stdlib.h>

int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head, *new_node, *temp;
    head = NULL;
    int choice = 1;
    while(choice)
    {
        new_node = (struct node*) malloc(sizeof(struct node));
        printf("Please enter data\n");
        scanf("%d", &new_node->data);
        new_node->next = 0;
        if(head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
        printf("Do you want to continue?(1 or 0)\n");
        scanf("%d", &choice);
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
