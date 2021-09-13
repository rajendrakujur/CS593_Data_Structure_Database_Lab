/*This program is last updated by RAJENDRA KUJUR (214161008) at 18/08/2021 19:20*/

#include <iostream>
#include <limits.h>
#include <unistd.h>
using namespace std;

// structure definition of process
struct Process
{
    int arrival_time;
    int burst_time;
    int start_time;
    int end_time;
    int waiting_time;
    int turn_around_time;
    bool executed;
};

// function to take input for all the processes
void takeInput(struct Process p[], int number_of_process)
{
    for (int index = 0; index < number_of_process; index++)
    {
        cout << "\nEnter details for process " << (index + 1) << " : ";
        cout << "\nEnter Arrival Time : ";
        cin >> p[index].arrival_time;
        cout << "Enter Burst Time : ";
        cin >> p[index].burst_time;
        p[index].executed = false;
    }
}

// make a copy of the original process s that while printing the final result burst time can be printed
void makeCopy(struct Process p[], struct Process copy[], int number_of_process)
{
    for (int index = 0; index < number_of_process; index++)
    {
        copy[index].arrival_time = p[index].arrival_time;
        copy[index].burst_time = p[index].burst_time;
        copy[index].executed = p[index].executed;
    }
}

// calculates the total burst time of all the processes and returns
int totalTime(struct Process p[], int number_of_process)
{
    int total_time = 0;
    for (int index = 0; index < number_of_process; index++)
    {
        total_time += p[index].burst_time;
    }
    return total_time;
}

// returns the process number having minimum burst time at a time
int findMin(struct Process p[], int number_of_process, int time_counter)
{
    int minimum_time = INT_MAX;
    int minimum_index = 0;

    for (int index = 0; index < number_of_process; index++)
    {
        if (p[index].burst_time > 0 && p[index].burst_time < minimum_time && p[index].arrival_time <= time_counter)
        {
            minimum_index = index;
            minimum_time = p[index].burst_time;
        }
    }
    return minimum_index;
}

// completes the process executin in Shortest remaining time first fashion
void SRTF(struct Process p[], struct Process copy[], int number_of_process)
{
    // calculates the total time by which all the process will finish their execution
    int total_time = totalTime(p, number_of_process);

    // index that is currently having minimum burst time conflict will be resolved by process ID
    int min_index;

    // travel by one unit of time in each iteration
    for (int time_elapsed = 0; time_elapsed < total_time; time_elapsed++)
    {
        min_index = findMin(p, number_of_process, time_elapsed);

        // updates the burst time of minindex process
        p[min_index].burst_time -= 1;

        // if the process is executed first time then update its start time and change its executed flag to true
        if (p[min_index].executed == false)
        {
            p[min_index].start_time = time_elapsed;
            p[min_index].executed = true;
        }

        // if the process completed its execution then update its end time and therefore calculate its waiting time and turn around time
        if (p[min_index].burst_time == 0)
        {
            p[min_index].end_time = time_elapsed + 1;
            p[min_index].turn_around_time = p[min_index].end_time - p[min_index].arrival_time;
            p[min_index].waiting_time = p[min_index].turn_around_time - copy[min_index].burst_time;
        }
    }
}

// prints the final result in table format
void printResult(struct Process p[], struct Process copy[], int number_of_process)
{
    // to store total waiting time and total turn around time
    int total_waiting_time = 0;
    int total_turn_around_time = 0;

    cout << "\n\nProcess \tArrival Time\tBurst Time\tStarting Time\tFinishing Time\tTurn Around Time\tWaiting Time\n";
    cout << "----------------------------------------------------------------------------------------------------------------\n";
    for (int index = 0; index < number_of_process; index++)
    {
        cout << "P" << (index + 1) << "\t\t" << p[index].arrival_time << "\t\t" << copy[index].burst_time << "\t\t" << p[index].start_time << "\t\t" << p[index].end_time << "\t\t" << p[index].turn_around_time << "\t\t" << p[index].waiting_time;
        cout << endl;

        // calculate the total_waiting_time for all the processes
        total_waiting_time += p[index].waiting_time;

        // calculate the total_turn_around_time for all the processes
        total_turn_around_time += p[index].turn_around_time;
    }

    float avg_waiting_time = float(total_waiting_time) / float(number_of_process);
    float avg_turn_around_time = float(total_turn_around_time) / float(number_of_process);

    cout << "\nAverage Waiting Time : " << avg_waiting_time;
    cout << "\nAverage Turn Arount Time : " << avg_turn_around_time;
}

// main function execution begins here
int main()
{
    // prompts the user for the number of the processes
    int number_of_process;
    cout << "Enter number of processes : ";
    cin >> number_of_process;

    // declare a structure and its copy (to print the result in well formatted manner)
    struct Process p[number_of_process];
    struct Process copy[number_of_process];

    // take input for all the processes
    takeInput(p, number_of_process);

    // copy the contents into copy structure
    makeCopy(p, copy, number_of_process);

    // call the CPU scheduling technique
    SRTF(p, copy, number_of_process);

    // print the final result
    printResult(p, copy, number_of_process);
    cout << endl;

    return 0;
}
