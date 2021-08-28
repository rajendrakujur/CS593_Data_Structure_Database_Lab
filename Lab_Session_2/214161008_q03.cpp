/*Last update by RAJENDRA KUJUR (214161008) on 24-08-2021 at 19:11*/

#include <iostream>
using namespace std;

// printout function that prints the required ouput
void printOutput(int nums[], int nums_size)
{
    int result[nums_size];

    for (int index = 0; index < nums_size; index++)
    {
        // for each index start result with 1
        result[index] = 1;
        for (int inner_index = 0; inner_index < nums_size; inner_index++)
        {
            // if current index matches with element's index then skip the element
            if (inner_index != index)
            {
                result[index] *= nums[inner_index];
            }
        }
    }

    // print the output
    for (int index = 0; index < nums_size; index++)
    {
        cout << result[index] << " ";
    }
    printf("\n");
}

// main function execution begins
int main()
{
    int array_size;
    cout << "Enter array size : ";
    cin >> array_size;
    int array[array_size];

    cout << "Enter array elements : ";
    for (int index = 0; index < array_size; index++)
    {
        cin >> array[index];
    }

    printOutput(array, array_size);
    return 0;
}