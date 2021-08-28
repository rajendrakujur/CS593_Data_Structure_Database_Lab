/*Last update by RAJENDRA KUJUR (214161008) on 21-08-2021 at 21:11*/

#include <iostream>
using namespace std;

// function to swap characters
void swap(char &first_char, char &second_char)
{
    char temp_char = first_char;
    first_char = second_char;
    second_char = temp_char;
}

// function that reverses the string
void reverseString(string &input_string)
{
    // variable to calculate string length
    int string_length = 0;
    while (input_string[string_length] != '\0')
    {
        string_length++;
    }

    int front_pointer = 0;
    int rear_pointer = string_length - 1;
    bool change_front_pointer = false;
    bool change_rear_pointer = false;

    // continue loop till front_pointer <= rear_pointer
    while (front_pointer <= rear_pointer)
    {
        if ((input_string[front_pointer] >= 'a' && input_string[front_pointer] <= 'z') || (input_string[front_pointer] >= 'A' && input_string[front_pointer] <= 'Z'))
        {
            change_front_pointer = true;
        }
        // if front pointer is pointing to special character don't change it
        else
        {
            front_pointer++;
            change_front_pointer = false;
        }
        if ((input_string[rear_pointer] >= 'a' && input_string[rear_pointer] <= 'z') || (input_string[rear_pointer] >= 'A' && input_string[rear_pointer] <= 'Z'))
        {
            change_rear_pointer = true;
        }
        // if rear pointer is pointing to special character
        else
        {
            rear_pointer--;
            change_rear_pointer = false;
        }
        // if front and rear both are not pointing to special character then swap and change front & rear pointer accordingly
        if (change_front_pointer && change_rear_pointer)
        {
            swap(input_string[front_pointer], input_string[rear_pointer]);
            front_pointer++;
            rear_pointer--;
        }
    }
}

// main function execution begins
int main()
{
    string input_string;

    cout << "Enter string : ";
    getline(cin, input_string);
    reverseString(input_string);

    // print updated string
    cout << input_string << endl;
    return 0;
}