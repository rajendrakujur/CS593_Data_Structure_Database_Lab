// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <limits.h>

// function that returns minimum cost overall
int minimumTotalCost(int rod_length[], int number_of_sticks)
{
    // to iterate over rod_length
    int rod_index;
    // intialized the result(minimum_total_cost) to maximum value possible
    int minimum_total_cost = INT_MAX;

    // index for iterating inside loop
    int rod_index_inner_loop;
    // to count the total cost with respect to each length
    int total_cost;
    for (rod_index = 0; rod_index < number_of_sticks; rod_index++)
    {
        // for every rod_length total_cost will be reset to zero
        total_cost = 0;
        for (rod_index_inner_loop = 0; rod_index_inner_loop < number_of_sticks; rod_index_inner_loop++)
        {
            if (rod_length[rod_index] > rod_length[rod_index_inner_loop])
            {
                total_cost += rod_length[rod_index] - rod_length[rod_index_inner_loop];
            }
            else
            {
                total_cost += rod_length[rod_index_inner_loop] - rod_length[rod_index];
            }
        }
        // if total_cost for that respective rod is less than minimum_total_cost at particular
        // moment then update total_cost
        if (total_cost < minimum_total_cost)
        {
            minimum_total_cost = total_cost;
        }
    }
    return minimum_total_cost;
}

// main function
int main()
{
    int number_of_sticks;

    // prompts the user for number of sticks
    printf("Enter number of sticks : ");
    scanf("%d", &number_of_sticks);

    // to iterate over rod lengths
    int rod_index;
    int rod_length[number_of_sticks];

    // taking input from user
    printf("Enter rod lengths : ");
    for (rod_index = 0; rod_index < number_of_sticks; rod_index++)
    {
        scanf("%d", &rod_length[rod_index]);
    }

    printf("%d", minimumTotalCost(rod_length, number_of_sticks));
}
