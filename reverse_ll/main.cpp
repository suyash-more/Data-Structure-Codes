
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct Node
{
 int data;
 struct Node* next;
}Node;
struct Node* head = NULL;

struct Node* Reverse(struct Node* head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    head = prev;
    return head;
}

Node* Insert(Node* head, int data)
{
 Node* temp =(Node*)malloc(sizeof(struct Node));
 temp->data = data; temp->next = NULL;
 if (head == NULL) head = temp;
 else {
  Node* temp1 = head;
  while (temp1->next != NULL) temp1 = temp1->next;
  temp1->next = temp;
 }
 return head;
}
void Print(Node* head) {
 while (head != NULL) {
  printf("%d", head->data);
  head = head->next;
 }
 printf("\n");
}

void ReversePrintRec(Node* headp){
    if(headp==NULL) return;
    ReversePrintRec(headp->next);
    cout<<headp->data<< " ";
}

void PrintRec(Node* headp){
    if(headp==NULL) return;
    cout<<headp->data<< " ";
    PrintRec(headp->next);
}

/*void ReverseRec(Node* headp){
if(headp->next!=NULL){
    head=headp;
    return;
}
ReverseRec(headp->next);
Node *q=headp->next;
q->next=headp;
headp->next=NULL;
Print(headp);
}*/

int main() {

 head = Insert(head, 2);
 head = Insert(head, 4);
 head = Insert(head, 6);
 head = Insert(head, 8);
 Print(head);
 head = Reverse(head);
 //ReverseRec(head);
 Print(head);
}
