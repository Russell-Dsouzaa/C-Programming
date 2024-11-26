// This is an alternative method to the one in 'Factorial.c'. The other one used a while loop while this method uses recursion. It recursively calls the same function within which it is defined.

#include <stdio.h>
#include <stdlib.h>

int Factorial (int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }

    return number * Factorial(number - 1);
}

int main()
{
    int number,result;

    printf("Enter an integer: ");
    scanf("%d",&number);
    printf("\n");

    result = Factorial(number);

    printf("Factorial of %d is: %d\n",number,result);

    return 0;
}