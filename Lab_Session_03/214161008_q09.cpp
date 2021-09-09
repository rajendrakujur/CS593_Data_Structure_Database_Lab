/*Last update by RAJENDRA KUJUR (214161008) on 09-09-2021 at 16:54*/

#include <iostream>
using namespace std;

// returns the maximum product possible from the give array
int maximumProduct(int array[], int array_size)
{
    if (array_size == 1)
    {
        return array[0];
    }

    int minimum = array[0];
    int maximum = array[0];
    int max_overall = array[0];

    for (int index = 1; index < array_size; index++)
    {
        // update maximum
        if (array[index] > array[index] * maximum)
        {
            if (array[index] > array[index] * minimum)
            {
                maximum = array[index];
            }
            else
            {
                maximum = array[index] * minimum;
            }
        }
        else
        {
            if (array[index] * maximum > array[index] * minimum)
            {
                maximum = array[index] * maximum;
            }
            else
            {
                maximum = array[index] * minimum;
            }
        }

        // update minimum
        if (array[index] > array[index] * maximum)
        {
            if (array[index] * maximum > array[index] * minimum)
            {
                minimum = array[index] * minimum;
            }
            else
            {
                minimum = array[index] * maximum;
            }
        }
        else
        {
            if (array[index] > array[index] * minimum)
            {
                minimum = array[index] * minimum;
            }
            else
            {
                minimum = array[index];
            }
        }

        // if maximum is greater that max_overall then updated max_overall
        max_overall = max_overall > maximum ? max_overall : maximum;
    }
    return max_overall;
}

// main function execution begins here
int main()
{
    int array_size;

    cout << "Enter number of elements in array : ";
    cin >> array_size;
    int array[array_size];

    cout << "Enter array elements : ";
    for (int index = 0; index < array_size; index++)
    {
        cin >> array[index];
    }

    cout << maximumProduct(array, array_size);
    cout << endl;
    return 0;
}
