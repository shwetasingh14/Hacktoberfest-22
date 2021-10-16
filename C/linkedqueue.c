#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;
void Enqueue(int item);
void Dequeue();
void DisplayOfElements();
void Peek();
int IsEmpty();
int main()
{
    while (1)
    {
        int c, num, check;
        printf("\n<-----------***----------->\n");
        printf("\n\tEnter one of the keys \n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display of Elements\n");
        printf("5.check if Empty\n");
        printf("6.exit()\n");
        printf("Enter your choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &num);
            Enqueue(num);
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Peek();
            break;
        case 4:
            DisplayOfElements();
            break;
        case 5:
            check = IsEmpty();
            if (check == 1)
                printf("Queue is empty/underflown\n");
            else
                printf("Queue is not empty\n");
            break;
        case 6:
            return 0;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}
void Enqueue(int item)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory unavailable\n");
        return;
    }
    if (IsEmpty())
    {
        tmp->data = item;
        tmp->next = NULL;
        front = rear = tmp;
    }
    else
    {
        tmp->data = item;
        tmp->next = NULL;
        rear->next = tmp;
        rear = tmp;
    }
    printf("%d inserted\n", item);
}
void Dequeue()
{
    if (IsEmpty())
    {
        printf("QUEUE underflown\n");
        return;
    }
    struct node *tmp;
    tmp = front;
    if (front == rear)
    {
        printf("%d is removed\n", tmp->data);
        front = NULL;
    }
    else
    {
        printf("%d is removed\n", tmp->data);
        front = front->next;
    }
    free(tmp);
}
void Peek()
{
    printf("First Element = %d", front->data);
}
int IsEmpty()
{
    if (front == NULL)
        return 1;
    else
        return 0;
}
void DisplayOfElements()
{
    struct node *tmp;
    if (IsEmpty())
    {
        printf("Queue underflown\n");
        return;
    }
    tmp=front;
    while(tmp!=NULL)
    {
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
}