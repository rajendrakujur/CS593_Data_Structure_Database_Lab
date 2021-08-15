// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <math.h>

// pre defined array
int array[] = {-6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2};

// main function
int main()
{
    // calculating array size
    int array_size = sizeof(array) / sizeof(int);
    // to iterate over array, works as index
    int array_index = 0;

    // cumulative array sum initialized to zero
    int cumulative_array_sum = 0;

    for (array_index = 0; array_index < array_size; array_index++)
    {
        cumulative_array_sum += array[array_index];
    }

    // mean and standard declared as float, initialized to 0.0
    float mean = 0.0;
    float standard_deviation = 0.0;

    //Usual formula for calculating mean for 1-D array
    mean = (float)cumulative_array_sum / (float)array_size;

    // cumulative squared difference from mean
    float cumulative_squared_diff = 0;
    for (array_index = 0; array_index < array_size; array_index++)
    {
        cumulative_squared_diff += pow((array[array_index] - mean), 2);
    }

    // the usual formula for calculating standard deviation in a 1-D array
    standard_deviation = sqrt((float)cumulative_squared_diff / (float)array_size);

    // print results
    printf("Mean : %f \n", mean);
    printf("Standard Deviation : %f \n", standard_deviation);
    return 0;
}