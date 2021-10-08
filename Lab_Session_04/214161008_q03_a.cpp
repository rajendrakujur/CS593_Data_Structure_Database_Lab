/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 07:20*/

#include <iostream>
#include <fstream>
using namespace std;

// Queue structure
struct Queue
{
    int data[10000];
    int front;
    int rear;
    int size;
};

// stack structure since stack is to implemented using two queues
struct Stack
{
    struct Queue q1, q2;
};

// returns true if the queue is empty
bool isEmpty(struct Queue q)
{
    if (q.front == q.rear && q.front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns true if the queue is full
bool isFull(struct Queue q)
{
    if (q.front == (q.rear + 1) % q.size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// enqueues an element in the queue
void enqueue(struct Queue &q, int number)
{
    if (isEmpty(q))
    {
        q.front = (q.front + 1) % q.size;
    }
    q.rear = (q.rear + 1) % q.size;
    q.data[q.rear] = number;
}

// dequeues an element and returns
int dequeue(struct Queue &q)
{
    if (!isEmpty(q))
    {
        int number = q.data[q.front];

        // if front and rear is pointing to same element it means queue is having only one element
        // after popping queue will be empty so make changes accordingly
        if (q.front == q.rear)
        {
            q.rear = -1;
            q.front = q.rear;
        }
        else
        {
            q.front = (q.front + 1) % q.size;
        }
        return number;
    }
    else
    {
        return -1;
    }
}

// pushes number onto the stack
void push(struct Stack &s, int number)
{
    enqueue(s.q1, number);
}

// swap the queues q1 and q2
void swap(struct Queue &q1, struct Queue &q2)
{
    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

// pops and element from stack and returns the elements
int pop(struct Stack &s)
{
    int return_value = -1;

    // if q1 is empty then directly return -1
    if (isEmpty(s.q1))
    {
        return return_value;
    }

    // otherwise keep popping till the last element from the queue gets stored in return_value and return that value
    while (!isEmpty(s.q1))
    {
        return_value = dequeue(s.q1);
        if (!isEmpty(s.q1))
        {
            enqueue(s.q2, return_value);
        }
    }

    // atlast swap q1 and q2
    swap(s.q1, s.q2);
    return return_value;
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

// reads from file and perform operation and write the result into another file
void readFile()
{
    ifstream fin;
    fin.open("214161008_q03_a_input.txt");

    ofstream fout;
    fout.open("214161008_q03_a_output.txt");

    // declare a stack s
    struct Stack s;

    // intialize queues variable for the stack
    s.q1.front = -1;
    s.q1.rear = -1;

    s.q2.front = -1;
    s.q2.rear = -1;

    string line;
    fin >> line;
    s.q1.size = stringToInteger(line);
    s.q2.size = 10000;

    int choice;
    int number;

    if (s.q1.size <= 0)
    {
        fout << "Stack can't accomodate any element.\n";
        return;
    }

    // read till we reach the end of the file
    while (!fin.eof())
    {
        fin >> line;
        choice = stringToInteger(line);

        switch (choice)
        {
        // reads the number and pushes to the stack
        case 1:
            fin >> line;
            number = stringToInteger(line);

            // fout << "s.q1.front  " << s.q1.front << "s.q1.rear  " << s.q1.rear << endl;
            ;
            if (!isFull(s.q1))
            {
                push(s, number);
                fout << "Pushed : " << number;
            }
            else
            {
                fout << "Stack is Full.";
            }
            break;

        // pops and print the element if stack wasn't empty
        case 2:
            number = pop(s);
            if (number == -1)
            {
                fout << "Stack is empty.";
            }
            else
            {
                fout << "Popped : " << number;
            }
            break;
        default:
            fout << "Not a valid option.";
        }
        fout << endl;
    }

    fin.close();
    cout << "\nRead from file '214161008_q03_a_input.txt'.";
    fout.close();
    cout << "\nWritten to file '214161008_q03_a_input.txt'.";
}

// main function execution begins here
int main()
{
    readFile();
    cout << endl;
    return 0;
}
