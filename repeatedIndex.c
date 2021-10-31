#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a;
    int *ptr;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    ptr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (ptr[j]==ptr[i])
            {
               a= i+1;
               break;
            }
            
        }
        
    }
    printf("Index of 1st repeated number in the array is %d\n",a);
    return 0;
}
