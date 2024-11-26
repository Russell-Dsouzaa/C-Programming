#include <stdio.h>
#include <stdlib.h>

int Factorial(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }

    int result = 1;

    while (number != 0)
    {
        result = result * number;
        number--;
    }

    return result;
}

int main()
{
    int number,result;

    printf("Enter an integer: ");
    scanf("%d",&number);
    printf("\n");

    result = Factorial(number);  // we could define 'result' variable here too, as, int result = Factorial(number);

    printf("Factorial of %d is: %d\n",number,result);

    return 0;
}