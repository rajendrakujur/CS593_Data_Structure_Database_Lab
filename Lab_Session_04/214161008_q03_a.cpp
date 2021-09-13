/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 07:20*/

#include <iostream>
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
struct stack
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
    if (!isFull(q))
    {
        if (isEmpty(q))
        {
            q.front = (q.front + 1) % q.size;
        }
        q.rear = (q.rear + 1) % q.size;
        q.data[q.rear] = number;
    }
    else
    {
        cout << "\nStack is Full.";
    }
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
void push(struct stack &s, int number)
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
int pop(struct stack &s)
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

// main function execution begins here
int main()
{
    // declare a stack s
    struct stack s;

    // intialize queues variable for the stack
    s.q1.front = -1;
    s.q1.rear = -1;

    s.q2.front = -1;
    s.q2.rear = -1;

    s.q1.size = 1000;
    s.q2.size = 1000;

    int choice;
    int number;

    while (1)
    {
        cout << "1.Push\n2.Pop\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number : ";
            cin >> number;
            push(s, number);
            break;
        case 2:
            number = pop(s);
            if (number == -1)
            {
                cout << "Stack is empty.";
            }
            else
            {
                cout << "Popped number " << number;
            }
            break;
        default:
            return 0;
        }
        cout << endl;
    }
    return 0;
}
