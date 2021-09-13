/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 15:36*/

#include <iostream>
using namespace std;

// structure of Deuque
struct Dequeue
{
    int data[100000];
    int front;
    int rear;
    int size;
};

// returns true if Dequeue q is full
bool isFull(struct Dequeue q)
{
    if ((q.rear + 1) % q.size == q.front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns true if Dequeue q is empty
bool isEmpty(struct Dequeue q)
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

// enqueues an element at the front of the queue
void enqueueFront(struct Dequeue &q, int number)
{
    if (isFull(q))
    {
        cout << "\nQueue is Full.";
    }
    else
    {
        // if queue is empty i.e. the incoming number will be the first one then update both
        if (isEmpty(q))
        {
            q.rear = (q.rear + 1) % q.size;
            q.front = (q.front + 1) % q.size;
        }
        // other wise update only front
        else
        {
            q.front = (q.front - 1) % q.size;
        }
        // if front is pointing to negative index then add dequeue size so that it becomes circular
        if (q.front < 0)
        {
            q.front += q.size;
        }
        q.data[q.front] = number;
    }
}

// enqueues an element at the rear of the queue
void enqueueRear(struct Dequeue &q, int number)
{
    if (isFull(q))
    {
        cout << "\nQueue is Full.";
    }
    else
    {
        // if queue is empty i.e. the incoming number will be the first one then update both
        if (isEmpty(q))
        {
            q.rear = (q.rear + 1) % q.size;
            q.front = (q.front + 1) % q.size;
        }

        // other wise update only rear
        else
        {
            q.rear = (q.rear + 1) % q.size;
        }
        q.data[q.rear] = number;
    }
}

// dequeueue an element from the front and returns
int dequeueFront(struct Dequeue &q)
{
    int return_value = -1;
    if (isEmpty(q))
    {
        return return_value;
    }
    else
    {
        return_value = q.data[q.front];

        // if the queue has only one element left then update front and rear pointer to -1 so that queue will be empty
        if (q.front == q.rear && q.front != -1)
        {
            q.front = -1;
            q.rear = -1;
        }
        // other wise update only front pointer
        else
        {
            q.front = (q.front + 1) % q.size;
        }
    }
    return return_value;
}

// dequeues an element from the rear and returns
int dequeueRear(struct Dequeue &q)
{
    int return_value = -1;

    if (isEmpty(q))
    {
        return return_value;
    }
    else
    {
        return_value = q.data[q.rear];

        // if the queue has only one element left then update front and rear pointer to -1 so that queue will be empty
        if (q.front == q.rear && q.front != -1)
        {
            q.front = -1;
            q.rear = -1;
        }
        // other wise update only front pointer
        else
        {
            q.rear = (q.rear - 1) % q.size;
            // if rear < 0 then increment by Dequeue size so that it can be made circular
            if (q.rear < 0)
            {
                q.rear += q.size;
            }
        }
    }
    return return_value;
}

// main function execution begins here
int main()
{
    struct Dequeue q;
    q.front = -1;
    q.rear = -1;

    // temporaries we will need later
    int number;
    int choice;

    cout << "Enter Dequeue size : ";
    cin >> q.size;

    // Loop  will continue till the user wants
    while (1)
    {
        cout << "\n1.Enqueue number at front.";
        cout << "\n2.Enqueue number at the end.";
        cout << "\n3.Dequeue from front";
        cout << "\n4.Dequeue from end";
        cout << "\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to enqueue : ";
            cin >> number;

            enqueueFront(q, number);
            break;

        case 2:
            cout << "Enter number to enqueue : ";
            cin >> number;

            enqueueRear(q, number);
            break;

        case 3:
            number = dequeueFront(q);
            if (number != -1)
            {
                cout << "Dequeued element : " << number;
            }
            else
            {
                cout << "Dequeue is empty.";
            }
            break;

        case 4:
            dequeueRear(q);
            if (number != -1)
            {
                cout << "Dequeued element : " << number;
            }
            else
            {
                cout << "Dequeue is empty.";
            }
            break;

        default:
            continue;
        }

        // ask the user whether s/he want to continue
        cout << "\nDo you want to continue? 0(for no) 1 or any other(for yes) : ";
        cin >> choice;

        if (!choice)
        {
            break;
        }
    }

    return 0;
}
