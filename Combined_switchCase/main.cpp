//INSERTION OF NODES AT THE BEGINNING AND IT'S DISPLAY

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head;

void Print () {
    Node* temp = head;

    while (temp != NULL){
        printf ("%d | ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// The meat of the program
void Insert (int data, int position) {
    Node* newNode = new Node();

    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* previousNode = head;
    for (int i = 0; i < position - 2; i++) {
        previousNode = previousNode->next;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;
}
void append(int data)
{
    Node *temp=head;
    int pos=1;
    while(temp!=NULL)
    {
        temp=temp->next;
        pos++;
    }
    Insert(data,pos);
}
void prepend(int data)
{
    Node *temp=head;
    int pos=1;
    Insert(data,1);
}

void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1){
        head = temp1->next;
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
    {
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
void Reverse()
{
    Node *nextnode,*prev,*current;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev ;
}

int main () {
    head = NULL;
    int choice,data,pos;
    do{
            cout<<"\n\tPress 1 : Insertion at pos\n\tPress 2 : Append\n\tPress 3 : Prepend\n\tPress 4 : Delete"
            "\n\tPress 5 : Print list\n\tPress 6 : Reverse\n\tPress 7 : Exit"<<endl;
            cout<<"\nChoice : ";
            cin>>choice;
            switch(choice){
            case 1:
                cout<<"Enter the data : ";
                cin>>data;
                cout<<"Enter the Position : ";
                cin>>pos;
                Insert(data,pos);
                break;
            case 2:
                cout<<"Enter the data : ";
                cin>>data;
                append(data);
                break;
            case 3:
                cout<<"Enter the data : ";
                cin>>data;
                prepend(data);
                break;
            case 4:
                cout<<"Enter the Position : ";
                cin>>pos;
                Delete(pos);
                break;
            case 5:
                Print ();
                break;
            case 6:
                Reverse();
                break;
            default:
                cout<<"Wrong input Entered..!!"<<endl;
            }
    }while(choice!=7);
}
