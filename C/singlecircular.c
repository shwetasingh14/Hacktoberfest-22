#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *last = NULL;
struct node *create_node()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));
    printf("Enter new data: ");
    scanf("%d", &newnode->data);
    printf("\nNode has been created\n");
    return newnode;
}
void checkempty()
{

    if (last == NULL)
    {
        printf("\nList is null\n");
    }
    else
        printf("\nList has some nodes\n");
}
void traverse()
{
     //printf("Hellop");
    if (last == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
     //printf("Hellok");
    struct node *ptr;
    ptr = last->next;
    do
    {
       // printf("Helloin");
        printf("\n\t%d", ptr->data);
        ptr = ptr->next;
    }while (ptr!=last->next);
     //printf("Helloinj");
}
void insert_first()
{
    struct node *newnode = create_node();
    if (last == NULL)
    {
        last=newnode;
        last->next=last;
        printf("Node is inserted and there is only one node\n");
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        printf("\nNode inserted\n");
    }
    //head = newnode;
}
void insert_last()
{
    struct node *temp;
    struct node *newnode = create_node();

    if (last == NULL)
    {
        last = newnode;
        last->next = last;
        printf("\nNode is inserted and there is only one node\n");
        return;
    }

    newnode->next = last->next;
    last->next = newnode;
    last = newnode;

    printf("\nNode inserted at end\n");
}
void insert_at()
{
    int i, loc, item;
    if (last == NULL)
    {
        printf("Empty List cant delete \n");
        return;
    }
    struct node *temp;
    struct node *newnode = create_node();
    printf("\nEnter the location after which you want to insert ");
    scanf("\n%d", &loc);
    temp = last->next;
    for (i = 0; i < loc; i++)
    {
        temp = temp->next;
        if (temp->next == last->next)
        {
            printf("\ncan't insert\n");
            return;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("\nNode inserted\n");
}
void delete_first()
{
    struct node *ptr;
    if (last == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = last->next;
        last->next = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
void delete_last()
{
    struct node *ptr, *ptr1;
    if (last == NULL)
    {
        printf("\nlist is empty\n");
    }
    else if (last->next == last)
    {
        last = NULL;
        //free(last);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = last->next;
        while (ptr->next != last->next)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = last->next;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}
void delete_at()
{
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\n Enter the location of the node after which you want to perform deletion \n");
    scanf("%d", &loc);
    ptr = last->next;

    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr->next == last->next)
        {
            printf("\nCan't delete\n");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d \n", loc + 1);
}
void count()
{
    struct node *tmp;
    int count = 0;
    if (last == NULL)
    {
        count = 0;
        printf("\n0elements are present\n");
        return;
    }
    tmp = last->next;
    if (last == last->next)
        count = 0;
    else
    {
        while (tmp->next != last->next)
        {
            count += 1;
            tmp = tmp->next;
        }
        count += 1;
    }
    printf("\n%d elements are present\n", count);
}
void search()
{
    if (last == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    struct node *tmp = last->next;int flag=0;
    printf("Enter the element to search: ");
    int num;
    scanf("%d", &num);
    do
    {
        if (tmp->data == num)
        {
            flag=1;
            break;
        }
        tmp = tmp->next;
    } while (tmp != last);
    if(flag)
        printf("Element is present \n");
        else
        printf("Not found\n");
}
int main()
{
    int k, c = 1;
    do
    {

        printf("\n\tEnter the defined key to make a choice\n\t1 for tranverse the linked list\n");
        printf("\t2 check the list is empty\n");
        printf("\t3 insert a node at a particular position\n");
        printf("\t4 delete a node at a particular position (at beginning/end/any position)\n");
        printf("\t5 count total no of nodes \n");
        printf("\t6 search for an element in the node\n");
        printf("\t7 to to exit\n");
        scanf("%d", &k);
        int n;
        switch (k)
        {
        case 1:
            traverse();
            break;
        case 2:
            checkempty();
            break;
        case 3:

            printf("Enter 1 for first position,2 for last position and 3 for any position: ");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                insert_first();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_at();
                break;
            default:
                printf("\nWrong choice\n");
                break;
            }
            break;
        case 4:

            printf("Enter 1 for first position,2 for last position and 3 for any position: ");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
                delete_first();
                break;
            case 2:
                delete_last();
                break;
            case 3:
                delete_at();
                break;
            default:
                printf("\nWrong choice\n");
                break;
            }
            break;
        case 5:
            count();
            break;
        case 6:
            search();
            break;
        case 7:
            c = 0;
            break;
        default:
            printf("\nWrong choice entered\n");
        }
    } while (c);

    return 0;
}