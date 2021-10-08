/*This program is last updated by RAJENDRA KUJUR (214161008) at 07-10-2021 23:40*/

#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;

// structure definition of process
struct Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int start_time;
    int end_time;
    int waiting_time;
    int turn_around_time;
    int response_time;
    bool executed;
    bool went_inside_queue;
};

// structure of queue that stores processes as its data elements
struct Queue
{
    struct Process data[10000];
    int front;
    int rear;
    int size;
};

// returns true if queue is empty
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

// returns true if queue is full
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

// enqueues a process at the rear of the queue
void enqueue(struct Queue &q, struct Process p)
{
    if (!isFull(q))
    {
        if (isEmpty(q))
        {
            q.front = (q.front + 1) % q.size;
        }
        q.rear = (q.rear + 1) % q.size;
        q.data[q.rear] = p;
    }
}

// dequeues a process from the front of the queue and returns it
struct Process dequeue(struct Queue &q)
{
    struct Process p = q.data[q.front];
    if (!isEmpty(q))
    {
        struct Process p = q.data[q.front];
        if (q.front == q.rear)
        {
            q.rear = -1;
            q.front = q.rear;
        }
        else
        {
            q.front = (q.front + 1) % q.size;
        }
        return p;
    }
    else
    {
        return p;
    }
}

// make a copy of the original process s that while printing the final result burst time can be printed
void makeCopy(struct Process p[], struct Process copy[], int number_of_process)
{
    for (int index = 0; index < number_of_process; index++)
    {
        copy[index].process_id = p[index].process_id;
        copy[index].arrival_time = p[index].arrival_time;
        copy[index].burst_time = p[index].burst_time;
        copy[index].executed = false;
        copy[index].went_inside_queue = false;
    }
}

// returns the first process starting time
int minimum_starting_time(struct Process p[], int number_of_process)
{
    int min_time = INT_MAX;
    for (int index = 0; index < number_of_process; index++)
    {
        if (p[index].arrival_time < min_time)
        {
            min_time = p[index].arrival_time;
        }
    }
    return min_time;
}

// calculates the total burst time of all the processes and returns
int totalTime(struct Process p[], int number_of_process)
{
    int total_time = minimum_starting_time(p, number_of_process);
    for (int index = 0; index < number_of_process; index++)
    {
        total_time += p[index].burst_time;
    }
    return total_time;
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

// swaps the processes p and q
void swap(struct Process &p, struct Process &q)
{
    struct Process temp = p;
    p = q;
    q = temp;
}

// writes the final result to the file
void writeToFile(struct Process p[], struct Process copyProcess[], int number_of_processes)
{
    ofstream fout;
    fout.open("214161008_q10_a_output.txt");

    // to store total waiting time and total turn around time
    int total_waiting_time = 0;
    int total_turn_around_time = 0;

    fout << "PID\t\tA.T.\tB.T.\tS.T.\tE.T.\tT.A.T.\tW.T.\tR.T.\n";
    fout << "__________________________________________________________________________\n";
    for (int p_index = 0; p_index < number_of_processes; p_index++)
    {
        for (int index = 0; index < number_of_processes; index++)
        {
            if (copyProcess[index].process_id == p[p_index].process_id)
            {
                fout << p[p_index].process_id << "\t\t" << p[p_index].arrival_time << "\t\t" << p[p_index].burst_time << "\t\t" << copyProcess[index].start_time << "\t\t" << copyProcess[index].end_time << "\t\t" << copyProcess[index].turn_around_time << "\t\t" << copyProcess[index].waiting_time << "\t\t" << copyProcess[index].response_time << endl;

                // calculate the total_waiting_time for all the processes
                total_waiting_time += copyProcess[index].waiting_time;

                // calculate the total_turn_around_time for all the processes
                total_turn_around_time += copyProcess[index].turn_around_time;
            }
        }
    }

    float avg_waiting_time = float(total_waiting_time) / float(number_of_processes);
    float avg_turn_around_time = float(total_turn_around_time) / float(number_of_processes);

    fout << "\nAverage Turn Arount Time : " << avg_turn_around_time;
    fout << "\nAverage Waiting Time : " << avg_waiting_time;
    fout << "\n\nPID : Process ID";
    fout << "\nA.T. : Arrival Time";
    fout << "\nB.T. : Burst Time";
    fout << "\nS.T. : Starting Time";
    fout << "\nE.T. : End Time";
    fout << "\nT.A.T : Turn Around Time";
    fout << "\nW.T. : Waiting Time";
    fout << "\nR.T. : Response Time";
    fout.close();
    cout << "\nWritten to file '214161008_q10_a_output.txt' ";
}

// returns the index matching with copyProcess processID
int findMatchingIndex(struct Process p[], int process_id, int number_of_processes)
{
    for (int index = 0; index < number_of_processes; index++)
    {
        if (p[index].process_id == process_id)
        {
            return index;
        }
    }
}

// completes the process execution in round robin fashion
void readFile()
{
    ifstream fin;
    fin.open("214161008_q10_a_input.txt");

    string line;

    // to skip the words and colon
    fin >> line >> line;

    fin >> line;
    int time_quantum = stringToInteger(line);

    getline(fin, line);
    getline(fin, line);
    getline(fin, line);

    // to store all the process details
    struct Process p[10000];
    int number_of_processes = 0;

    // read til we reach to the end of the file
    while (!fin.eof())
    {
        fin >> line;
        p[number_of_processes].process_id = stringToInteger(line);
        fin >> line;
        p[number_of_processes].arrival_time = stringToInteger(line);
        fin >> line;
        p[number_of_processes].burst_time = stringToInteger(line);
        number_of_processes++;
    }
    fin.close();
    cout << "\nRead from file '214161008_q10_a_input.txt' ";

    // make a copy of orignal Processes
    struct Process copyProcess[number_of_processes];
    int total_time = totalTime(p, number_of_processes);

    makeCopy(p, copyProcess, number_of_processes);

    // sort according to the arrival time
    for (int index = 0; index < number_of_processes; index++)
    {
        for (int inner_index = index + 1; inner_index < number_of_processes; inner_index++)
        {
            if (copyProcess[index].arrival_time > copyProcess[inner_index].arrival_time)
            {
                swap(copyProcess[index], copyProcess[inner_index]);
            }
        }
    }

    int time_elapsed = 0;
    int index = 0;
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    q.size = number_of_processes;

    bool any_process_executed = false;
    int previous_process_id = -1;

    // keep loop continue till all the processes executed
    while (time_elapsed < total_time)
    {
        any_process_executed = false;

        // if any prcess has arrived till the time of time elapsed then enqueue it
        for (index = 0; index < number_of_processes; index++)
        {
            if (copyProcess[index].went_inside_queue == false && copyProcess[index].arrival_time <= time_elapsed)
            {
                enqueue(q, copyProcess[index]);
                copyProcess[index].went_inside_queue = true;
            }
        }

        // if the process has been already executed earlier i.e. it was paused due to time quantum
        // again enqueue such processes
        for (index = 0; index < number_of_processes; index++)
        {
            if (copyProcess[index].process_id == previous_process_id && copyProcess[index].burst_time > 0)
            {
                enqueue(q, copyProcess[index]);
            }
        }
        // if the queue is not empty
        if (!isEmpty(q))
        {
            struct Process execute_this_process = dequeue(q);
            any_process_executed = true;
            int temp_index;
            // find the process using process ID returned from dequeue
            for (temp_index = 0; temp_index < number_of_processes; temp_index++)
            {
                if (execute_this_process.process_id == copyProcess[temp_index].process_id)
                {
                    execute_this_process = copyProcess[temp_index];
                    break;
                }
            }

            // if the process is being executed for the first time then update its executed status
            // and save the start time of process
            if (copyProcess[temp_index].executed == false)
            {
                copyProcess[temp_index].start_time = time_elapsed;
                copyProcess[temp_index].executed = true;
                copyProcess[temp_index].response_time = copyProcess[temp_index].start_time - copyProcess[temp_index].arrival_time;
            }
            // if process is having remaining burst time greater than time quantum then update its burst time
            if (copyProcess[temp_index].burst_time > time_quantum)
            {
                copyProcess[temp_index].burst_time -= time_quantum;
                time_elapsed += time_quantum;
            }
            // otherwise update the process' burst time to zero and time elapsed accordingly
            else
            {
                time_elapsed += copyProcess[temp_index].burst_time;
                copyProcess[temp_index].burst_time = 0;
            }

            // if the process is completely executed then calculate waiting, turn around time using end time
            if (copyProcess[temp_index].burst_time == 0)
            {
                copyProcess[temp_index].end_time = time_elapsed;
                copyProcess[temp_index].turn_around_time = copyProcess[temp_index].end_time - copyProcess[temp_index].arrival_time;
                copyProcess[temp_index].waiting_time = copyProcess[temp_index].turn_around_time - p[findMatchingIndex(p, copyProcess[temp_index].process_id, number_of_processes)].burst_time;
            }
            previous_process_id = copyProcess[temp_index].process_id;
        }

        // if no process executed during current time instance then increase time_elapsed
        if (!any_process_executed)
        {
            time_elapsed++;
        }
        // print(q);
    }

    // write the final results to the file
    writeToFile(p, copyProcess, number_of_processes);
}

// main function execution begins here
int main()
{
    readFile();
    cout << endl;
    return 0;
}
