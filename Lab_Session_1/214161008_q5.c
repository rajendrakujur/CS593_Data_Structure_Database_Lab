// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>

// pre-defined array array and LEFT_ROTATE & RIGHT_ROTATE
int array[] = {3, 2, 4, 5, 6, 7, 1};
int LEFT_ROTATE = 3;
int RIGHT_ROTATE = 2;

// returns array rotated by LEFT_ROTATE
int *leftRotate(int duplicate_array[], int array_size)
{
    // to iterate over array
    int array_index = 0;
    // number of times array rotated
    int rotate_count = 0;

    // each time array is rotated left by 1
    for (rotate_count = 1; rotate_count <= LEFT_ROTATE; rotate_count++)
    {
        // array elements will be moved one by one to their left first element
        // is stored and will be assigned to the last index at last
        int first_element = duplicate_array[0];
        for (array_index = 0; array_index < array_size - 1; array_index++)
        {
            duplicate_array[array_index] = duplicate_array[array_index + 1];
        }
        duplicate_array[array_size - 1] = first_element;
    }
    return duplicate_array;
}

// returns array rotated by RIGHT_ROTATE
int *rightRotate(int duplicate_array[], int array_size)
{
    // to iterate over array
    int array_index = 0;
    // number of times array rotated
    int rotate_count = 0;

    // each time array is right rotated by one
    for (rotate_count = 1; rotate_count <= RIGHT_ROTATE; rotate_count++)
    {
        // array elements will be moved one by one to their right last element
        // is stored and will be assigned to the zeroth index at last
        int last_element = duplicate_array[array_size - 1];
        for (array_index = array_size - 1; array_index >= 0; array_index--)
        {
            duplicate_array[array_index] = duplicate_array[array_index - 1];
        }
        duplicate_array[0] = last_element;
    }
    return duplicate_array;
}

// main function
int main()
{
    int array_size = sizeof(array) / sizeof(int);
    // to iterate over array
    int array_index;
    // declared a local duplicated array of same size to avoid the updation on main array i.e. declared globally
    int duplicate_array[array_size];

    // copying the global array into local duplicate array
    for (array_index = 0; array_index < array_size; array_index++)
    {
        duplicate_array[array_index] = array[array_index];
    }

    int *left_rotated_array = leftRotate(duplicate_array, array_size);

    // print results
    printf("Left Rotated Array : ");
    for (array_index = 0; array_index < array_size; array_index++)
    {
        printf("%d ", left_rotated_array[array_index]);
    }

    // copying the global array again into local duplicate array since the duplicated array has been updated
    for (array_index = 0; array_index < array_size; array_index++)
    {
        duplicate_array[array_index] = array[array_index];
    }

    int *right_rotated_array = rightRotate(duplicate_array, array_size);

    // prints result
    printf("\nRight Rotated Array : ");
    for (array_index = 0; array_index < array_size; array_index++)
    {
        printf("%d ", right_rotated_array[array_index]);
    }

    return 0;
}