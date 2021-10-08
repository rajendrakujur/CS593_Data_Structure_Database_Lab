/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 15:36*/

#include <iostream>
#include <fstream>
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

// enqueues an element at the rear of the queue
void enqueueRear(struct Dequeue &q, int number)
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
    fin.open("214161008_q05_a_input.txt");

    ofstream fout;
    fout.open("214161008_q05_a_output.txt");

    struct Dequeue q;
    q.front = -1;
    q.rear = -1;

    // temporaries we will need later
    int number;
    int choice;
    string line;

    fin >> line;
    q.size = stringToInteger(line);

    if (q.size <= 0)
    {
        fout << "Can't accomodate any elements.\n";
        return;
    }

    fout << "Sequence of Execution : \n";
    // Loop  will continue till the user wants
    while (!fin.eof())
    {
        fin >> line;
        choice = stringToInteger(line);

        switch (choice)
        {
        // enqueues element at the front of the dequeue
        case 1:
            fin >> line;
            number = stringToInteger(line);

            if (isFull(q))
            {
                fout << "Dequeue is Full.";
            }
            else
            {
                enqueueFront(q, number);
                fout << "Enqueued (front) : " << number;
            }
            break;

        // enqueues element at the rear of the dequeue
        case 2:
            fin >> line;
            number = stringToInteger(line);

            if (isFull(q))
            {
                fout << "Dequeue is Full.";
            }
            else
            {
                enqueueRear(q, number);
                fout << "Enqueued (rear) : " << number;
            }
            break;

        // dequeues an element from the front if queue wasn't empty
        case 3:
            number = dequeueFront(q);
            if (number != -1)
            {
                fout << "Dequeued (front) : " << number;
            }
            else
            {
                fout << "Dequeue is empty.";
            }
            break;

        // dequeues an element from the rear if queue wasn''t empty
        case 4:
            number = dequeueRear(q);
            if (number != -1)
            {
                fout << "Dequeued (rear) : " << number;
            }
            else
            {
                fout << "Dequeue is empty.";
            }
            break;

        default:
            fout << "Not a valid option.";
        }
        fout << endl;
    }

    fin.close();
    cout << "\nRead from file '214161008_q05_a_input.txt'.";
    fout.close();
    cout << "\nWritten to file '214161008_q05_a_output.txt'.";
}

// main function execution begins here
int main()
{
    readFile();
    cout << endl;
    return 0;
}