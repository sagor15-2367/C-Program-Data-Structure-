//Linked list insertion at specific position in C
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
int getCurrSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void insertAfterNthNode(int n, int data, struct Node** head)
{
    int size = getCurrSize(*head);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(n < 0 || n > size)
        printf("Invalid position to insert\n");
    else if(n == 0){
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;

        while(--n)
            temp=temp->next;

        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

void display(struct Node* node){

    printf("Linked List : ");

    // as linked list will end when Node is Null
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{


    struct Node* head = NULL;
    struct Node* node2 = NULL;
    struct Node* node3 = NULL;
    struct Node* node4 = NULL;


    head =  (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));
    node4 = (struct Node*)malloc(sizeof(struct Node));


    head->data = 10;
    head->next = node2;
    node2->data = 20;
    node2->next = node3;

    node3->data = 30;
    node3->next = node4;

    node4->data = 40;
    node4->next = NULL;


    display(head);


    insertAfterNthNode(1, 15, &head);
    insertAfterNthNode(3, 25, &head);
    insertAfterNthNode(5, 35, &head);
    insertAfterNthNode(7, 45, &head);
    display(head);
    insertAfterNthNode(-2, 100, &head);

    insertAfterNthNode(10, 200, &head);

    return 0;
}
