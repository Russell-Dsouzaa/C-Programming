/* This program provides an alternative method to solve the Last Occurence of an array element. The other LastOccurence program(LastOccurence.c) makes use of BS only to locate one of the 
occurences of the parget element and then it switches onto Linear Search to find the index of that element's last occurence. In this method, we would continue using BS even after we locate one 
of the element's occurences*/

#include <stdio.h>
#include <stdlib.h>

int LastOccurence(int* array,int start,int end,int target)
{
    while (start <= end)
    {
        int middle = (start + end) / 2;  /* Apparently, 'start + end' expression is not ideal since if start and end's addition exceeds int datatype's limits, it would lead to an Integer Overflow
         hence, BlackBox AI suggests to use the following expression instead, 'int middle = start + (end - start)/2'. the division operation would be done before addition operation*/

        if (array[middle] == target)    /* when an integer overflow occurs, the variable's value wraps around to the other end. i.e. if it exceeds max value, it wraps onto the min value.
        For Example, a = 2147483647 and b = 1; then a+b = 214783648 which exceeds int datatype's upper-limit. hence a+b become -2147483648. */
        {
            if (middle == end || array[middle + 1] != target)
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

int main()
{
    int array1[10] = {1,2,2,2,2,6,7,8,9,10};
    int size = sizeof(array1) / sizeof(array1[0]);
    int start = 0, end = size - 1, target;

    printf("Enter target integer: \n");
    scanf("%d",&target);

    int result = LastOccurence(array1,start,end,target);

    if (result == (-1))
    {
        printf("Entered integer is not present in the array: {1,2,2,2,2,6,7,8,9,10} :(\n");
    }
    else
    {
        printf("Target integer is present at index: %d\n",result);
    }

    return 0;
}