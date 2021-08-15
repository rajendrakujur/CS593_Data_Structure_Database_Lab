// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <stdbool.h>

// main function
int main()
{
    // to take array size as input at first
    int array_size;
    // to iterate over array
    int array_index;

    printf("Enter array size : ");
    scanf("%d", &array_size);

    int array[array_size];
    // boolean variable to check whether element is present or not
    bool check_element[array_size];

    // prompting user for array input and initializing check element as false at all indexes
    printf("Enter array : ");
    for (array_index = 0; array_index < array_size; array_index++)
    {
        scanf("%d", &array[array_index]);
        check_element[array_index] = false;
    }

    //variable for storing results
    int missing_number, duplicate_number;

    // iterating array to get the duplicate number
    for (array_index = 0; array_index < array_size; array_index++)
    {
        // if respective check_element is already true means that element is already present
        if (check_element[array[array_index] - 1] == true)
        {
            duplicate_number = array[array_index];
        }
        // update the respective check_element to true if element is present
        check_element[array[array_index] - 1] = true;
    }

    // iterating array for missing number
    // the respective check element will be false if number is missing
    for (array_index = 0; array_index < array_size; array_index++)
    {
        if (check_element[array_index] == false)
        {
            missing_number = array_index + 1;
        }
    }

    // printing results
    printf("\nMissing Number : %d", missing_number);
    printf("\nDuplicate Number : %d", duplicate_number);
}