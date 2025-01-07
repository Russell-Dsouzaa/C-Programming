#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

bool LinearSearch (int* array,int size,int target)
{
    for (int i = 0;i < size;i++)
    {
        if (array[i] == target)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int size = 0,target = INT_MAX;

    printf("Enter the size of the array : ");
    scanf("%d",&size);

    int *array = (int*)malloc(sizeof(int) * size);
    for (int i = 0;i < size; i++)
    {
        printf("Enter the %dth array element : ",i);
        scanf("%d",&array[i]);
    }

    printf("Target Element : ");
    scanf("%d",&target);

    bool result = LinearSearch(array,size,target);

    if (result == true)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not found :(\n");
    }

    return 0;
}