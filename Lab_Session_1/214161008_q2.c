// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <stdbool.h>

// return true if number is even, false if odd
bool isEven(int number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// return true if number is positive else returns false
bool isPositive(int number)
{
    if (number > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// return true if number is negative else returns false
bool isNegative(int number)
{
    if (number < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// main function
int main()
{
    int array[25];
    // array_index to iterate over the array, works as index for array
    int array_index;
    // counts the appearance of positive numbers
    int count_positive = 0;
    // counts the appearance of negative numbers
    int count_negative = 0;
    // counts the appearance of even numbers
    int count_even = 0;
    // counts the appearance of odd numbers
    int count_odd = 0;

    // loop to take input the array from the user
    for (array_index = 0; array_index < 25; array_index++)
    {
        scanf("%d", &array[array_index]);
    }

    // loop to check the element is positive, negative,either odd or even
    for (array_index = 0; array_index < 25; array_index++)
    {
        if (isPositive(array[array_index]))
        {
            count_positive += 1;
        }
        else if (isNegative(array[array_index]))
        {
            count_negative += 1;
        }
        if (isEven(array[array_index]))
        {
            count_even += 1;
        }
        else if (!isEven(array[array_index]))
        {
            count_odd += 1;
        }
    }

    // Print results
    printf("Count of positive numbers : %d\n", count_positive);
    printf("Count of negative numbers : %d\n", count_negative);
    printf("Count of even numbers : %d\n", count_even);
    printf("Count of odd numbers : %d\n", count_odd);

    return 0;
}