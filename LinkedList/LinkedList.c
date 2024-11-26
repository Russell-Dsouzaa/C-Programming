#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int value;
    struct LinkedList* next;
}LinkedList;

LinkedList* create(int val)
{
    LinkedList* newnode = (LinkedList*)malloc(sizeof(LinkedList));

    if (newnode == NULL)
    {
        free(newnode);
        exit(1);
    }

    newnode->value = val;
    newnode->next = NULL;
    return newnode;
}

void append(LinkedList** head,int value)
{
    LinkedList* newnode = create(value);

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    LinkedList* temp = *head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

int main()
{
    LinkedList* head = NULL;

    append(&head,1);
    append(&head,2);

    LinkedList* current = head;

    while(current != NULL)
    {
        printf("%d\n",current->value);
        current = current->next;
    }

    while(head != NULL)
    {
        LinkedList* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}