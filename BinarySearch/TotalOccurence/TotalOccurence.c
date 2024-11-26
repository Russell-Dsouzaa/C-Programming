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

int LastOccurence (int* array,int start,int target,int end)
{
    while (start <= end)
    {
        int middle = start + (end - start) / 2;

        if (array[middle] == target)
        {
            if (middle == end || array[middle] != array[middle + 1])
            {
                return middle;
            }
            else
            {
                start = middle + 1;
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

int TotalOccurence (int* array,int start,int target,int end)
{
    int one = FirstOccurence(array,start,target,end);
    int two = LastOccurence(array,start,target,end);
    int result = two - one;

    if (one == (-1) || two == (-1))
    {
        return (-1);
    }

    return (result + 1);
}

int main()
{
    int array1[10] = {1,2,2,2,2,6,7,8,9,10};
    int size = sizeof(array1) / sizeof(array1[0]);
    int start = 0,end = size - 1, target;

    printf("Enter target integer: \n");
    scanf("%d",&target);

    int result = TotalOccurence(array1,start,target,end);

    if (result == (-1))
    {
        printf("Target integer is not present in array: {1,2,2,2,2,6,7,8,9,10} :( hence it's total number of Occurences is 0, I guess.\n");
    }
    else
    {
        printf("Total number of occurences of the target integer: %d\n",result);
    }

    return 0;
}