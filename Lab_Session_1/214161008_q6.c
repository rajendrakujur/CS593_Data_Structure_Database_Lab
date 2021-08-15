// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// pre-defined array
int array[] = {16, 17, 4, 3, 5, 2};
// intialized max element to INT_MIN so that last element is always the leader
int max_element = INT_MIN;

// function that recursively prints the leaders in the array
void printLeaders(int array_index)
{
    // Reached to array_index -1
    if (array_index < 0)
    {
        return;
    }
    else
    {
        // to store the leader element in each recursive call
        int leader_element;
        // to be updated to true every recursive call we get leader_element else by default false
        bool flag = false;

        // leader_element is updated if it is greater than the maximum elements to its right side
        // if leader is updated then flag will also be updated to true to keep track
        if (array[array_index] > max_element)
        {
            leader_element = array[array_index];
            max_element = array[array_index];
            flag = true;
        }
        // recursive call with indexing - 1
        printLeaders(array_index - 1);
        // if the flag is set true then we had recieved leader element in that recursive call
        if (flag)
        {
            printf("%d ", leader_element);
        }
    }
}

// main function
int main()
{
    int array_size = sizeof(array) / sizeof(int);
    // calling printLeaders function with last elements's index
    printLeaders(array_size - 1);
    return 0;
}