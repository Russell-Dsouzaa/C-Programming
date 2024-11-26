// We need to sort the array in ascending or descending order before-hand

#include <stdio.h>
#include <stdlib.h>

int FOBinarySearch (int* array,int start,int end,int target)
{
    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (array[middle] == target)
        {
            while (array[middle] == array[middle - 1])
            {
                middle = middle - 1;
            }
            return middle;
        }
        else if (array[middle] < target)
        {
            start = middle + 1;
        }
        else{
            end = middle - 1;
        }
    }

    return -1;
}

int main()
{
    int array1[10] = {2,2,2,2,5,6,7,8,9,10};
    int size = sizeof(array1) / sizeof(array1[0]);
    int start = 0, end = size - 1, target;

    printf("Enter an integer: \n");
    scanf("%d",&target);

    int result = FOBinarySearch(array1,start,end,target);

    if (result == (-1))
    {
        printf("Entered integer is not present in the array: {1,2,3,4,5,6,7,8,9,10} :(\n");
    }
    else
    {
        printf("Enterd enteger found at index: %d\n",result);
    }

    return 0;
}