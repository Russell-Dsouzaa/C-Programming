/* This is an alternative method in contrast to the 'TotalOccurence.c' method. The other method finds out the first and last occurence of the target element and the
 calculates their difference to find out it's total number of occurences. Unlike the previous method, after finding either first or last occurence of the target element, we then count it's each occurence 
 in a linear-search format */

#include <stdio.h>
#include <stdlib.h>

int FirstOccurence (int* array,int start,int target,int end)
{
    while (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (array[middle] == target)
        {
            if (middle == 0 || array[middle] != array[middle - 1])
            {
                int count = 0;

                while (array[middle] == array[middle + 1])
                {
                    count = count + 1;
                    middle = middle + 1;
                }

                return count + 1;
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
    int start = 0,end = size - 1,target;

    printf("Enter target integer: \n");
    scanf("%d",&target);

    int result = FirstOccurence(array1,start,target,end); // we could use LastOccurence instead

    if (result == (-1))
    {
        printf("Target integer is not present in the array: {1,2,2,2,2,6,7,8,9,10} :(\n");
    }
    else
    {
        printf("Total number of occurences of the element '%d': %d\n",target,result);
    }

    return 0;
}