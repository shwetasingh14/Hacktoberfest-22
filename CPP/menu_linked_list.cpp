#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int v){
        data=v;
        next=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertAtPosition(node* &head, int val, int p){
    node* cur=head;
    node* temp=new node(val);
    node* pre;
    while(p--){
        pre=cur;
        cur=cur->next;
    }
    pre->next=temp;
    temp->next=cur;
}

void insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp= head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
}

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL\n";
}
void deleteFromHead(node* &head){
    node* del=head;
    head=head->next;
    delete del;
}

int main(){
    node* head=NULL;
    // int ch;
    while(1){
        int ch;
        cout << "\nMENU" << "\n1.Insert at head" << "\n2.Insert at tail" << "\n3.Insert at specific position" << "\n4.Delete from head" << "\n5.Display Linked List" << "\n6.Exit"<<"\nEnter your choice:";
    cin >> ch;
    int n;
    switch(ch){
        case 1: cout << "Enter element to insert:";
                cin >> n;
                insertAtHead(head,n);
                cout << "Element added successfully.";
                break;
        case 2: cout << "Enter element to insert:";
                cin >> n;
                insertAtTail(head,n);
                cout << "Element added successfully.";
                break;
        case 3: cout << "Enter element to insert:";
                cin >> n;
                int p;
                cout << "Enter position:";
                cin >> p; 
                insertAtPosition(head,n,p);
                cout << "Element added successfully.";
                break;
        case 4: deleteFromHead(head);
                cout << "Element deleted successfully.";
                break;
        case 5: printlist(head);
                break;
        case 6: exit(0);
        default: cout << "Enter valid input";
    }
    }
    
    
    return 0;
}
