/* This is an alternate method to find the First Occurence of an element within an array. The previous method in 'FirstOccurence.c' would prove to be slow since once we find one of 
the target elements, we then find the first occurence of that element(target element) in a linear-search fashion. In this method, once we find one of the occurences of the target element, we then 
keep using the Binary Search method(algorithm) to find that particular element's first occurence. */

#include <stdio.h>
#include <stdlib.h>

int FOBinarySearch(int* array,int start,int target,int end)
{
    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (array[middle] == target)
        {
            if (middle == 0 || array[middle] != array[middle - 1])
            {
                return middle;
            }
            else
            {
                end = middle - 1;
            }
        }
        else if (array[middle] < target)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    return (-1);
}

int main()
{
    int array1[10] = {1,2,2,2,2,6,7,8,9,10};
    int size = sizeof(array1) / sizeof(array1[0]);
    int start = 0, end = size - 1, target;

    printf("Enter target integer: \n");
    scanf("%d",&target);

    int result = FOBinarySearch(array1,start,target,end);

    if (result == (-1))
    {
        printf("Entered integer is not present in the array: {1,2,2,2,2,6,7,8,9,10} :(\n");
    }
    else
    {
        printf("Entered integer is present at index: %d\n",result);
    }

    return 0;
}