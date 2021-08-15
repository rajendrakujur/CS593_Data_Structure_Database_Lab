// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// prdefind light_bulbs working condition
bool light_bulb[] = {0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1};
// intensity a light_bulb has
int intensity = 2;

// function that returns the dark spot index
int darkSpotIndex()
{
    // calculate number of bulbs
    int number_of_bulbs = sizeof(light_bulb) / sizeof(bool);
    // to iterate over bulbs
    int bulb_index;
    // intensity the current index has from previous bulb
    int previous_bulb_intensity = 0;
    // must_have_bulb_within_index to avoid black spot at current index by default initialized to INT_MAX
    int must_have_bulb_within_index = INT_MAX;

    for (bulb_index = 0; bulb_index < number_of_bulbs; bulb_index++)
    {
        // if index has faulty bulb
        if (light_bulb[bulb_index] == false)
        {
            // if current index **should must** have bulb then return the index that asked for it
            if (bulb_index == must_have_bulb_within_index)
            {
                return (must_have_bulb_within_index - intensity);
            }
            // if previous_bulb_intensity was zero then update must_have_bulb_within_index
            if (previous_bulb_intensity == 0)
            {
                // update accordingly the lowest index will be assigned
                must_have_bulb_within_index = (bulb_index + intensity) > must_have_bulb_within_index ? must_have_bulb_within_index : (bulb_index + intensity);
            }
            // if bulb found to be working within must_have_bulb_within_index
            // update intensity and update must_have_bulb_within_index to maximum possible value
            else
            {
                previous_bulb_intensity -= 1;
                must_have_bulb_within_index = INT_MAX;
            }
        }
        // if current bulb is working update intensity
        else
        {
            previous_bulb_intensity = intensity;
        }
    }
    return -1;
}

int minimumWorkingLightToAvidBlackSpot()
{
    // calculate number of bulbs
    int number_of_bulbs = sizeof(light_bulb) / sizeof(bool);
    // since each light_bulb can cover (1+2*intensity) indices
    return 1 + (number_of_bulbs / (1 + 2 * intensity));
}

// main function
int main()
{
    printf("%d", darkSpotIndex());
    printf("\nMinimum bulbs to avoid darkspot : %d", minimumWorkingLightToAvidBlackSpot());
    return 0;
}