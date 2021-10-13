#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *last=NULL;
struct node *createnode()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node*));
    printf("Enter new data: ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}
void push();
void pop();
void check();
void display();
int main()
{
    int k, c = 1;
    do
    {
        printf("\n\tEnter one of the keys \n");
        printf("1 to check if stack is empty\n");
        printf("2 to display the contents of the stack\n");
        printf("3 to Push an element\n");
        printf("4 to Pop an element\n");
        printf("5 to exit\n");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
            check();
            break;
        case 2:
            display();
            break;
        case 3:
            push();
            break;
        case 4:
            pop();
            break;
        case 5:
            c = 0;
            break;
        default:
            printf("Wrong choice \n");
            break;
        }
    } while (c);
}
void push()
{
    struct node *temp;
    struct node *newnode = createnode();
    if (last == NULL)
    {
        last = newnode;
        last->next = last;
        printf("\nBlock pushed and only one node is present\n");
        return;
    }
    newnode->next = last->next;
    last->next = newnode;
    last = newnode;
    printf("\nBlock inserted\n");
}
void pop()
{
    struct node *ptr, *ptr1;
    if (last == NULL)
    {
        printf("\nstack is empty\n");
    }
    else if (last->next == last)
    {
        last = NULL;
        //free(last);
        printf("\nOnly block of the list deleted ...\n");
    }
    else
    {
        ptr1 = last;
        ptr=ptr1->next;
       do
        {
            ptr = ptr->next;
        } while (ptr->next != last);
        ptr->next=last->next;
        free(ptr1);
        last=ptr;
        printf("\nDeleted block ...\n");
    }
}
void display()
{
    if (last == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    struct node *ptr;
    ptr = last->next;
    do
    {
       printf("%d  ", ptr->data);
        ptr = ptr->next;
    }while (ptr!=last->next);
}
void check()
{
    if (last == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    else
    printf("Not empty\n");
}