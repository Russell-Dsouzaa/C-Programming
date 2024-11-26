#include <stdio.h>
#include <stdlib.h>

void Fibionacci (int number)
{
    int num1 = 0;
    int num2 = 1;

    while ((number-2) != 0)
    {
        int temp = num1 + num2;

        printf("%d\n",temp);
        num1 = num2;
        num2 = temp;
        number--;
    }
}

int main()
{
    int number = 0;

    printf("Enter the number of Fibionacci numbers you wish to see:");
    scanf("%d",&number);
    printf("\n");

    printf("0\n1\n");
    Fibionacci(number);

    return 0;
}