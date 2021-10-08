/*Last update by RAJENDRA KUJUR (214161008) on 08-10-2021 at 17:20*/

#include <iostream>
#include <fstream>
using namespace std;

// structure of two stack
struct TwoStack
{
    int data[100000];
    int front_stack_top;
    int rear_stack_top;
    int size;
};

// takes a string convert it into integer and returns
int stringToInteger(string str)
{
    int str_index = 0;

    // to check the coefficient
    int coefficient = 1;
    if (str[str_index] == '-')
    {
        coefficient = -1;
        str_index++;
    }

    int return_value = str[str_index++] - '0';

    while (str[str_index] != '\0')
    {
        return_value *= 10;
        return_value += str[str_index++] - '0';
    }
    return coefficient * return_value;
}

// if the array is full then new element can't be enqueued
bool isFull(struct TwoStack s)
{
    if (s.front_stack_top == -1 && s.rear_stack_top == 0)
    {
        return true;
    }
    else if (s.front_stack_top == s.size - 1 && s.rear_stack_top == s.size)
    {
        return true;
    }
    else if ((s.front_stack_top + 1) == s.rear_stack_top)
    {
        return true;
    }
    return false;
}

// pushes number in the top of front stack
void pushToFrontStack(struct TwoStack &s, int number)
{

    s.data[++s.front_stack_top] = number;
}

// pushes number in the top of rear stack
void pushToRearStack(struct TwoStack &s, int number)
{
    if (!isFull(s))
    {
        s.data[--s.rear_stack_top] = number;
    }
}

// pops an element and return from the top of front stack
// if no element present then return -1
int popFromFrontStack(struct TwoStack &s)
{
    if (s.front_stack_top == -1)
    {
        return -1;
    }
    else
    {
        return s.data[s.front_stack_top--];
    }
}

// pops an element and return from the top of rearstack
// if no element present then return -1
int popFromRearStack(struct TwoStack &s)
{
    if (s.rear_stack_top == s.size)
    {
        return -1;
    }
    else
    {
        return s.data[s.rear_stack_top++];
    }
}

// read from the file perform respective operation and write the respective output to output file
void readAndWriteFile()
{
    ifstream fin;
    fin.open("214161008_q01_input.txt");

    ofstream fout;
    fout.open("214161008_q01_output.txt");

    struct TwoStack s;
    string line;

    // sets the array size
    fin >> line;
    s.size = stringToInteger(line);

    s.front_stack_top = -1;
    s.rear_stack_top = s.size;

    if (s.size <= 0)
    {
        fout << "Can't accomodate any elements.\n";
        return;
    }

    int choice;
    int number;

    fout << "Sequence of outputs :\n";
    // read till the pointer reach to the end of the file
    while (!fin.eof())
    {
        fin >> line;
        choice = stringToInteger(line);

        switch (choice)
        {
        // reads an element and pushes into the front stack
        case 1:
            fin >> line;
            number = stringToInteger(line);
            if (!isFull(s))
            {
                fout << "pushed " << number << " to front stack";
                pushToFrontStack(s, number);
            }
            else
            {
                fout << "Front Stack is facing stack overflow";
            }
            fout << "\n";
            break;

        // reads an element and pushes into the rear stack
        case 2:
            fin >> line;
            number = stringToInteger(line);
            if (!isFull(s))
            {
                fout << "pushed " << number << " to rear stack";
                pushToRearStack(s, number);
            }
            else
            {
                fout << "Front Stack is facing stack overflow";
            }
            fout << "\n";
            break;

        // pops an element from the front stack
        case 3:
            number = popFromFrontStack(s);
            if (number == -1)
            {
                fout << "Front Stack is facing stack underflow\n";
            }
            else
            {
                fout << "Popped element from front stack : " << number << endl;
            }
            break;

        // pops an element from the rear stack
        case 4:
            number = popFromRearStack(s);
            if (number == -1)
            {

                fout << "Rear Stack is facing stack underflow\n";
            }
            else
            {
                fout << "Popped element from rear stack : " << number << endl;
            }
            break;

        // else print no valid option choosen
        default:
            fout << "Not a vaid option\n";
            break;
        }
    }
    fin.close();
    cout << "\nRead From file '214161008_q01_input.txt'";
    fout.close();
    cout << "\nWritten to file '214161008_q01_output.txt'";
}

// main function execution begins here
int main()
{
    readAndWriteFile();
    cout << endl;
    return 0;
}
