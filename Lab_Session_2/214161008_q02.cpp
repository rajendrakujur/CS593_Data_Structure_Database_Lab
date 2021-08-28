/*Last update by RAJENDRA KUJUR (214161008) on 27-08-2021 at 07:30*/

#include <iostream>
using namespace std;

// stack structure
struct stack
{
    char data[1000];
    int top;
    int size;
};

// returns true if stack is full, else returns false
bool isFull(struct stack s)
{
    if (s.top == s.size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns true if stack is empty, else returns false
bool isEmpty(struct stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pushes the ch character in stack
void push(struct stack &s, char ch)
{
    if (!isFull(s))
    {
        s.data[++s.top] = ch;
    }
}

// returns top element from stack
char top(struct stack s)
{
    return s.data[s.top];
}

// pops the top element from the stack and returns char
char pop(struct stack &s)
{
    if (!isEmpty(s))
    {
        return s.data[s.top--];
    }
    return -1;
}

// swaps two char
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

// reverses the given input string
void reverse(char input[])
{
    int length = 0;
    // calculates length
    while (input[length] != '\0')
    {
        length++;
    }
    // perform swap operation till length/2 between first and last element
    for (int index = 0; index < length / 2; index++)
    {
        swap(input[index], input[length - index - 1]);
    }
}

// makes the lowest number from given character array after removing remove_count numbers
void makeLeastNumber(char input[], int remove_count)
{
    // if remove_count zero print input number and exit
    if (remove_count == 0)
    {
        cout << input << endl;
        exit(0);
    }
    // calculate input length
    int length = 0;
    while (input[length] != '\0')
    {
        length++;
    }

    // define a stack
    struct stack s;
    s.size = 100;
    s.top = -1;
    // character array to store output
    char output[100];

    // scan input if new element is greater than top element of stack then remove that element from string
    for (int index = 0; index < length; index++)
    {
        while (remove_count && !isEmpty(s) && top(s) > input[index])
        {
            pop(s);
            remove_count--;
        }
        // if stack is empty or the number is lesser than top of stack push the read element into stack
        push(s, input[index]);
    }

    // if we reach till end of the given input and not done with removing elements
    // then keep popping the elements till remove_count becomes zero
    while (!isEmpty(s) && remove_count--)
    {
        pop(s);
    }

    if (isEmpty(s))
    {
        cout << "0";
        exit(0);
    }

    // to keep track of output
    int output_index = 0;

    // keep assigning elements from stack to output till it becomes empty
    while (!isEmpty(s))
    {
        output[output_index++] = pop(s);
    }

    // at last assign null character to output
    output[output_index] = '\0';

    // since we have store the result that popped from stack so reverse the output string
    reverse(output);

    cout << output << endl;
}

// main function execution begins here
int main()
{
    char input_string[100];
    int remove_count;

    cout << "Enter number : ";
    cin >> input_string;
    cout << "Enter n : ";
    cin >> remove_count;

    // call the function
    makeLeastNumber(input_string, remove_count);
    return 0;
}