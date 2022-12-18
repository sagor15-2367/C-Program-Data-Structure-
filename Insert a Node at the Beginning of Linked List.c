#include <stdio.h>

/* Node structure */
struct node{
    int data;
    struct node* next;
};

struct node* head;

//Insert node at the head of linked list
void insert_node(int data){

    /* Allocate memory to newly created node. */
    struct node* newnode=(struct node*)malloc(sizeof(struct node*));

    //data
    newnode->data = data;

    //Newnode points to head
    newnode->next = head;

    head = newnode;
}

void print(){

    struct node* p;
    p = head;

    //Traverse and print
    while(p != NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{

  /* Initially head is NULL, it doesn't point to any node. */

  head = NULL;

  /* insert_node function create new node dynamically. */
  insert_node(1);
  insert_node(9);
  insert_node(1);
  insert_node(1);
  insert_node(5);
  insert_node(2);
  insert_node(3);
  insert_node(6);
  insert_node(7);

/* Print value. */
  print();

  return 0;
}
