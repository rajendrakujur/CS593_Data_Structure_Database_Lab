// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <limits.h>

// function will return maximum machine height to obtain the required wood
int maxHeightMachine(int tree_height[], int number_of_trees, int required_wood)
{
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
    int number_of_trees;
    printf("Enter number of trees : ");
    scanf("%d", &number_of_trees);

    //  array named tree_height of size number_of_trees
    int tree_height[number_of_trees];
    // to iterate over tree_height
    int tree_index;

    // input from user
    for (tree_index = 0; tree_index < number_of_trees; tree_index++)
    {
        scanf("%d", &tree_height[tree_index]);
    }

    // prompts the user for required wood
    int required_wood;
    printf("Required wood : ");
    scanf("%d", &required_wood);

    printf("R : %d", maxHeightMachine(tree_height, number_of_trees, required_wood));
    return 0;
}