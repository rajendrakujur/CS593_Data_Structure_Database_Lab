/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 07:50*/

#include <iostream>
#include <fstream>
using namespace std;

// Stack structure
struct Stack
{
    int data[1000];
    int top;
    int size;
};

// Queue structure since Queue has to implemented using two stacks
struct Queue
{
    struct Stack s1, s2;
};

// returns true if stack is full otherwise false
bool isFull(struct Stack s)
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

// returns true if stack is empty
bool isEmpty(struct Stack s)
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

// pushes number onto the stack
void push(struct Stack &s, int number)
{
    s.data[++s.top] = number;
}

// pops an element from the stack and returns
int pop(struct Stack &s)
{
    if (!isEmpty(s))
    {
        return s.data[s.top--];
    }
    return -1;
}

// enqueues number into the queue
void enqueue(struct Queue &q, int number)
{
    push(q.s1, number);
}

// dequeues from queue and returns the number
int dequeue(struct Queue &q)
{
    int number, return_number;

    // push elements from stack_1 to stack_2
    while (!isEmpty(q.s1))
    {
        push(q.s2, pop(q.s1));
    }
    // if stack_2 is not empty then the first popping element will be returned
    if (!isEmpty(q.s2))
    {
        return_number = pop(q.s2);
    }
    else
    {
        return -1;
    }
    // now do the reverse push elements from stack_2 to stack_1
    while (!isEmpty(q.s2))
    {
        push(q.s1, pop(q.s2));
    }

    // finally return the number
    return return_number;
}

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

void readFile()
{
    ifstream fin;
    fin.open("214161008_q03b_input.txt");

    ofstream fout;
    fout.open("214161008_q03b_output.txt");

    // queue declaration
    struct Queue q;

    // initializing stack parameters for the queue
    q.s1.top = -1;
    q.s2.top = -1;

    string line;
    fin >> line;
    q.s1.size = stringToInteger(line);
    q.s2.size = 1000;

    int choice;
    int number;

    if (q.s1.size <= 0)
    {
        fout << "Queue can't accomodate any element.\n";
        return;
    }

    // read till we reach the end of the file
    while (!fin.eof())
    {
        fin >> line;
        choice = stringToInteger(line);

        switch (choice)
        {

        // reads the number and enqueues to the queue
        case 1:
            fin >> line;
            number = stringToInteger(line);

            if (!isFull(q.s1))
            {
                enqueue(q, number);
                fout << "Enqueued  " << number;
            }
            else
            {
                fout << "Queue is full.";
            }
            break;
        // dequeues an element from the queue and prints if queue wasn't empty
        case 2:
            number = dequeue(q);
            if (number == -1)
            {
                fout << "Queue is empty.";
            }
            else
            {
                fout << "Dequeued number " << number;
            }
            break;
        default:
            fout << "Not a valid option.";
        }
        fout << endl;
    }
    fin.close();
    std::cout << "\nRead from file '214161008_q03b_input.txt'.";
    fout.close();
    std::cout << "\nWritten to file '214161008_q03b_input.txt'.";
}

// main function execution begins here
int main()
{
    readFile();
    std::cout << endl;
    return 0;
}
