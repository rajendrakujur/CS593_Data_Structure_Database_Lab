// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <limits.h>

// predefined array
int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};

// returns the largest sum in subarray
int largestSumInSubarray()
{
    int array_size = sizeof(array) / sizeof(int);
    // to iterate over array
    int array_index;
    // to iterate over array inside loop
    int array_index_inner_loop;
    // cumulative sum each time begins with zero
    int cumulative_sum;
    // maximum sum initialized as minimum value possible
    int maximum_sum = INT_MIN;

    // loop till the last element
    for (array_index = 0; array_index < array_size; array_index++)
    {
        cumulative_sum = 0;
        // for each index cumulative sum will be updated with its respective upcoming indexes
        for (array_index_inner_loop = array_index; array_index_inner_loop < array_size; array_index_inner_loop++)
        {
            cumulative_sum += array[array_index_inner_loop];
            // if cumulative_sum is greater than maximum_sum at any instance maximum sum is udated
            if (cumulative_sum > maximum_sum)
            {
                maximum_sum = cumulative_sum;
            }
        }
    }
    // return the final result
    return maximum_sum;
}

// main function
int main()
{
    printf("%d", largestSumInSubarray());
}
