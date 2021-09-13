/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 07:50*/

#include <iostream>
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
    if (!isFull(s))
    {
        s.data[++s.top] = number;
    }
    else
    {
        cout << "Queue is full.";
    }
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

// main function execution begins here
int main()
{
    // queue declaration
    struct Queue q;

    // initializing stack parameters for the queue
    q.s1.top = -1;
    q.s2.top = -1;
    q.s1.size = 1000;
    q.s2.size = 1000;

    int choice;
    int number;

    while (1)
    {
        cout << "1.Enqueue\n2.Dequeue\nAny other to exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number : ";
            cin >> number;
            enqueue(q, number);
            break;
        case 2:
            number = dequeue(q);
            if (number == -1)
            {
                cout << "Queue is empty.";
            }
            else
            {
                cout << "\nDequeued number " << number;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}
