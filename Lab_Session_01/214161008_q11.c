// Last updated by Rajendra Kujur (214161008) on 16-09-2021 07:35 PM

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int tree_height[] = {10, 18, 2, 37, 18, 26, 13};
int required_wood = 30;

int totalWood()
{
    int total_wood = 0;
    int number_of_trees = sizeof(tree_height) / sizeof(int);
    for (int index = 0; index < number_of_trees; index++)
    {
        total_wood += tree_height[index];
    }
    return total_wood;
}

// function will return maximum machine height to obtain the required wood
int maxHeightMachine()
{
    int number_of_trees;
    number_of_trees = sizeof(tree_height) / sizeof(int);

    // to iterate over tree
    int tree_index;
    // intialized max height to the lowest value possible
    int max_height = INT_MIN;

    // loop for finding the maximum height among the trees
    for (tree_index = 0; tree_index < number_of_trees; tree_index++)
    {
        if (max_height < tree_height[tree_index])
        {
            max_height = tree_height[tree_index];
        }
    }

    // intialized machine's height to tallest tree's height
    int machine_height = max_height;
    // to store total wood obtained
    int obtained_wood = 0;

    // if required wood is greateer than available wood then return -1
    if (required_wood > totalWood())
    {
        return -1;
    }

    // As soon as we get the required_wood >= obtained_wood the loop will terminate
    while (obtained_wood < required_wood)
    {
        // decreasing machines height by one in every iteration
        machine_height--;
        // each time if the tree height is greater than machines height
        // 1 unit f tree will be cut and updated
        for (tree_index = 0; tree_index < number_of_trees; tree_index++)
        {
            if (tree_height[tree_index] > machine_height)
            {
                obtained_wood++;
                tree_height[tree_index]--;
            }
        }
    }
    // returns machines height
    return machine_height;
}

// main function
int main()
{
    int height = maxHeightMachine();
    if (height != -1)
        printf("R : %d", height);
    else
        printf("Not enough available wood.");
    return 0;
}
