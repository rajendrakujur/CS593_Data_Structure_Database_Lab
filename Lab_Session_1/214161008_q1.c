// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>

// function that returns the number_of_appearance in an array by searching for number_to_search
int numberOfAppearance(int array[], int array_size, int number_to_search)
{
    // array_index to iterate over the array works as index for array
    int array_index;
    // counts the appearance of number if it is present default set to zero
    int total_appearance = 0;

    // loop to check the presence of number_to_search in array
    for (array_index = 0; array_index < 25; array_index++)
    {
        // Updating total appearance variable if it matches with the array element
        if (array[array_index] == number_to_search)
        {
            total_appearance += 1;
        }
    }
    return total_appearance;
}

// main function
int main()
{
    int array[25];
    // array_index to iterate over the array works as index for array
    int array_index;
    // number to be searched
    int number_to_search;
    // arra size initialized to 25
    int array_size = 25;
    // loop to take input the array from the user
    for (array_index = 0; array_index < 25; array_index++)
    {
        scanf("%d", &array[array_index]);
    }

    printf("Enter number you want to search : ");
    scanf("%d", &number_to_search);

    // to store the result of returning value
    int total_appearance = numberOfAppearance(array, array_size, number_to_search);
    // If element is present in the array then total_appearance will be greatere than zero
    // hence print the number_of_appearance
    // else print number not found
    if (total_appearance > 0)
    {
        printf("%d", total_appearance);
    }
    else
    {
        printf("%d is not present in array.", number_to_search);
    }
    return 0;
}