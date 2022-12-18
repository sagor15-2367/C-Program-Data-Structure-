#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void deleteEnd(struct Node** head){
    struct Node* temp = *head;
    struct Node* previous;

    if(*head == NULL){
        printf("Linked List Empty, nothing to delete");
        return;
    }
    if(temp->next == NULL){
        printf("%d deleted\n",(*head)->data);
        *head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;

    printf("%d deleted\n", temp->data);
    free(temp);
}

void display(struct Node* node){

    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n\n");
}

int main()
{
    struct Node* head = NULL;
    struct Node* node2 = NULL;
    struct Node* node3 = NULL;
    struct Node* node4 = NULL;
    struct Node* node5 = NULL;
    struct Node* node6 = NULL;

    head =  (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));
    node4 = (struct Node*)malloc(sizeof(struct Node));
    node5 = (struct Node*)malloc(sizeof(struct Node));
    node6 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 19;
    head->next = node2;
    node2->data = 11;
    node2->next = node3;
    node3->data = 52;
    node3->next = node4;
    node4->data = 3;
    node4->next = node5;
    node5->data = 6;
    node5->next = node6;
    node6->data = 7;
    node6->next = NULL;

    printf("Linked list: ");
    display(head);

    deleteEnd(&head);
    deleteEnd(&head);
    deleteEnd(&head);


    printf("\nLinked list: ");
    display(head);

    return 0;
}

