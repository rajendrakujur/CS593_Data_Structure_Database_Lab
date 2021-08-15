// Last updated by Rajendra Kujur (214161008) on 15-08-2021 11:51 AM

#include <stdio.h>
#include <stdbool.h>

// returns true if hidden meaning, false if not hidden
bool checkHidden(char text[])
{
    // to iterate over text
    int text_index;
    // length read from the string
    int word_length_from_string;
    // length calulated by last index - starting index
    int word_length = 0;

    //initialized starting index as zero for the first word
    int starting_index = 0;
    for (text_index = 0; text[text_index] != '\0'; text_index++)
    {
        // as soon as we encounter first space
        if (text[text_index] == ' ')
        {
            // calculate word length
            word_length = text_index - starting_index;
            // read word length from string
            word_length_from_string = text[++text_index] - 48;

            // if matches returns true
            if (word_length_from_string == word_length)
            {
                return true;
            }
            // else do updation to indices and set indices to the next words starting index
            else
            {
                text_index += 2;
                starting_index = text_index;
            }
        }
    }
    // If did not found any case where the meaning hidden hence return false
    return false;
}

// main functin
int main()
{
    char text[100];
    // prompts user for input
    printf("Enter text : ");
    gets(text);

    // function call to check whether hidden or not
    if (checkHidden(text))
    {
        printf("Hidden");
    }
    else
    {
        printf("Not Hidden");
    }
}