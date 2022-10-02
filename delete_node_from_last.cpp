#include<iostream>
using namespace std;
struct node
{
           int data;
           node *next;
};
node* insert_node(node *start,int x)
{
           node *temp=new node;
           temp->data=x;
           temp->next=NULL;
           if(start==NULL)
                      return temp;
           node *ptr=start;
           while(ptr->next!=NULL)
           {
                      ptr=ptr->next;
           }
           ptr->next=temp;
           return start;
}
void display(node *start)
{
           node *temp=start;
           while(temp!=NULL)
           {
                      cout<<temp->data<<" ";
                      temp=temp->next;
           }
}
void getNth(node *start,int n)
{
           int c=0;
           node *temp=start;
           node *temp1=start;
           while(temp!=NULL)
           {
                      temp=temp->next;
                      c++;
           }
           if(!c<n)
           {
                      for(int i=1;i<c-n+1;i++)
                                 temp1=temp1->next;
                      cout<<"\nData searched:"<<temp1->data;
           }
}
int main()
{
           node *sample=NULL;
           sample=insert_node(sample,10);
           sample=insert_node(sample,20);
           sample=insert_node(sample,30);
           sample=insert_node(sample,40);
           sample=insert_node(sample,50);
           display(sample);
           getNth(sample,3);
           return 0;
}
