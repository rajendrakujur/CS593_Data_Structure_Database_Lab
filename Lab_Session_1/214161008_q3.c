// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <stdbool.h>

// function to check the given condition
bool checkCondition(int array[], int array_size)
{
    // to iterate over array
    int array_index = 0;

    // compare each element till the middle of the array_size to the (array_size-array_index-1 )
    // if any of the element does not match then return false
    for (array_index = 0; array_index < array_size / 2; array_index++)
    {
        if (array[array_index] != array[array_size - array_index - 1])
        {
            return false;
        }
    }

    // if flow reaches this point means every element satisfies the condition hence return true
    return true;
}

// main function
int main()
{
    // array size to be input from user
    int array_size;
    printf("Enter array size : ");
    scanf("%d", &array_size);
    // declare the array of array_size
    int array[array_size];
    // variable to iterate over array
    int array_index;

    // Loop to take input array from the user
    for (array_index = 0; array_index < array_size; array_index++)
    {
        scanf("%d", &array[array_index]);
    }

    // it will print the condition result
    if (checkCondition(array, array_size))
    {
        printf("Condition satisfied.");
    }
    else
    {
        printf("Condition not satisfied.");
    }
}