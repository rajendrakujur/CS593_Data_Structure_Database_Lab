/*Last update by RAJENDRA KUJUR (214161008) on 05-10-2021 at 22:18*/

#include <iostream>
#include <fstream>
using namespace std;

// queue structure
struct Queue
{
    int data[10000];
    int size;
    int front;
    int rear;
};

// returns true f queue s empty
bool isEmpty(struct Queue q)
{
    if (q.front == -1 && q.rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns true if queue is full
bool isFull(struct Queue q)
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

// enqueues an element 'number' at the rear of queue
void enqueue(struct Queue &q, int number)
{
    if (!isFull(q))
    {
        // if the queue is empty then update both the pointers
        if (q.front == -1)
        {
            q.front = 0;
            q.rear = 0;
            q.data[q.rear] = number;
        }
        else
        {
            q.rear = (q.rear + 1) % q.size;
            q.data[q.rear] = number;
        }
    }
    else
    {
        cout << "Queue is full can't enqueue";
    }
}

// deuques an element from queue and returns it
int dequeue(struct Queue &q)
{
    if (!isEmpty(q))
    {
        int return_value = q.data[q.front];
        // if removing one element will make queue empty then update both pointers
        if (q.front == q.rear)
        {
            q.front = -1;
            q.rear = -1;
        }
        else
        {
            q.front = (q.front + 1) % q.size;
        }
        return return_value;
    }
    else
    {
        cout << "Queue is empty, Can't Dequeue.";
        return -1;
    }
}

// takes a string convert it into integer and returns
int stringToInteger(string str)
{
    int str_index = 0;
    int return_value = str[str_index++] - '0';

    while (str[str_index] != '\0')
    {
        return_value *= 10;
        return_value += str[str_index++] - '0';
    }
    return return_value;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// checks the queue if 'number' is present then returns true otherwise returns false
bool found(struct Queue &q, int number)
{
    if (q.front == -1 && q.rear == -1)
    {
        return false;
    }

    int array[q.size];
    bool flag = false;
    int index = 0;

    // store all the elements after dequeueing into an array
    while (!isEmpty(q))
    {
        array[index++] = dequeue(q);
    }

    // check in array if number is present then update flag
    int array_index;
    for (array_index = 0; array_index < index; array_index++)
    {
        if (array[array_index] == number)
        {
            flag = true;
            if ((array_index + 1) < index)
            {
                swap(array[array_index], array[array_index + 1]);
            }
        }
        enqueue(q, array[array_index]);
    }
    return flag;
}

// read from file and do required calculations
int readFromFile()
{
    string line;
    int number_of_frames = 0;
    int reference_string[100000];

    ifstream fin;
    fin.open("214161008_q08_input.txt");

    struct Queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 0;

    // skip the first two words
    fin >> line >> line;

    // make queue size as frame size
    fin >> line;
    q.size = stringToInteger(line);

    // skip two words
    fin >> line >> line;

    // read till the end of file
    while (!fin.eof())
    {
        fin >> line;
        reference_string[number_of_frames++] = stringToInteger(line);
    }
    fin.close();
    cout << "\nRead From File '214161008_q08_input.txt' ";

    int index = 0;
    int page_fault = 0;

    // loop till all the frames are scanned
    while (index < number_of_frames)
    {
        if (!isFull(q))
        {
            // if element is not found at queue then it will cause page fault
            if (!found(q, reference_string[index]))
            {
                enqueue(q, reference_string[index]);
                page_fault++;
            }
        }
        else
        {
            // if queue is full and frame is not present in queue then dequeue a frame and enqueue new frame in queue
            if (!found(q, reference_string[index]))
            {
                dequeue(q);
                enqueue(q, reference_string[index]);
                page_fault++;
            }
        }
        index++;
    }
    return page_fault;
}

// write the final result into the file
void writeToFile(int page_fault)
{
    ofstream fout;
    fout.open("214161008_q08_output.txt");

    fout << "Total Page faults : " << page_fault;

    fout.close();
    cout << "\nWritten to file '214161008_q08_output.txt' ";
}

// main function execution begins here
int main()
{
    int page_fault = readFromFile();
    writeToFile(page_fault);
    cout << endl;
    return 0;
}
