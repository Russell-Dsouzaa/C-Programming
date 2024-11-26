// We have to sort the array in ascending or descending order before-hand

#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int* array, int start, int target, int end)
{
    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (array[middle] == target)
        {
            return middle + 1;
        }
        else if (array[middle] < target)    // this is for, when the array is sorted in ascending order
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    return -1;
}

int main()
{
    int array1[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array1)/sizeof(array1[0]);
    int start = 0, end = size - 1, target;

    printf("Enter target integer: \n");
    scanf("%i",&target);

    int result = BinarySearch(array1,start,target,end);

    if (result == (-1))
    {
        printf("Entered integer is not present in the array {1,2,3,4,5,6,7,8,9,10} :(\n");
    }
    else
    {
        printf("Entered integer is present at index: %d\n",result);
    }

    return 0;
}