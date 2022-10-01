#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num <= 0)
    {
        printf("Please enter a positive integer!\n");

        printf("\nEnter an integer: ");
        scanf("%d", &num);
    }

    int count = 0;

    while (num)
    {
        num = num / 10;

        count++;
    }

    printf("The number has %d digits.\n", count);

    return 0;
}
