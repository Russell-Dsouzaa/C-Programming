#include <stdio.h>
#include <stdlib.h>

int Sum(int* array,int length)
{
    int sum = 0;

    for (int i = 0;i < length;i++)
    {
        sum = sum + array[i];
    }

    return sum;
}

int main()
{
    int array1[10] = {1,2,3,4,5};
    int size = sizeof(array1) / sizeof(array1[0]);

    int result = Sum(array1,size);

    printf("Sum: %d\n",result);

    return 0;
}