/*This program is last updated by RAJENDRA KUJUR (214161008) at 13-09-2021 19:20*/

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
        copy[index].process_id = p[index].process_id;
        copy[index].arrival_time = p[index].arrival_time;
        copy[index].burst_time = p[index].burst_time;
        copy[index].executed = p[index].executed;
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

// returns the process number having minimum burst time at a time
int findMin(struct Process copy[], int number_of_process, int time_counter)
{
    int minimum_time = INT_MAX;
    int minimum_index = -1;

    for (int index = 0; index < number_of_process; index++)
    {
        if (copy[index].burst_time != 0)
        {
            if (copy[index].burst_time < minimum_time)
            {
                if (copy[index].arrival_time <= time_counter)
                {
                    minimum_index = index;
                    minimum_time = copy[index].burst_time;
                }
            }
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
        min_index = findMin(copy, number_of_process, time_elapsed);
        if (min_index == -1)
        {
            continue;
        }
        // updates the burst time of minindex process
        copy[min_index].burst_time -= 1;

        // if the process is executed first time then update its start time and change its executed flag to true
        if (copy[min_index].executed == false)
        {
            copy[min_index].start_time = time_elapsed;
            copy[min_index].executed = true;
            copy[min_index].response_time = copy[min_index].start_time - copy[min_index].arrival_time;
        }

        // if the process completed its execution then update its end time and therefore calculate its waiting time and turn around time
        if (copy[min_index].burst_time == 0)
        {
            copy[min_index].end_time = time_elapsed + 1;
            copy[min_index].turn_around_time = copy[min_index].end_time - copy[min_index].arrival_time;
            copy[min_index].waiting_time = copy[min_index].turn_around_time - p[min_index].burst_time;
        }
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

// prints the final result in table format
void writeToFile(struct Process p[], struct Process copyProcess[], int number_of_process)
{
    ofstream fout;
    fout.open("214161008_q10_b_output.txt");

    // to store total waiting time and total turn around time
    int total_waiting_time = 0;
    int total_turn_around_time = 0;

    fout << "PID\t\tA.T.\tB.T.\tS.T.\tE.T.\tT.A.T.\tW.T.\tR.T.\n";
    fout << "______________________________________________________________________________________________________________\n";
    for (int p_index = 0; p_index < number_of_process; p_index++)
    {
        for (int index = 0; index < number_of_process; index++)
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

    float avg_waiting_time = float(total_waiting_time) / float(number_of_process);
    float avg_turn_around_time = float(total_turn_around_time) / float(number_of_process);

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
    cout << "\nWritten to file '214161008_q10_b_output.txt' ";
}

// reads the file and call required functions
void readFromFile()
{
    ifstream fin;
    fin.open("214161008_q10_b_input.txt");

    string line;

    getline(fin, line);
    getline(fin, line);
    // to store all the process details
    struct Process p[10000];
    int number_of_process = 0;

    // read til we reach to the end of the file
    while (!fin.eof())
    {
        fin >> line;
        p[number_of_process].process_id = stringToInteger(line);
        fin >> line;
        p[number_of_process].arrival_time = stringToInteger(line);
        fin >> line;
        p[number_of_process].burst_time = stringToInteger(line);
        number_of_process++;
    }
    fin.close();
    cout << "\nRead from file '214161008_q10_b_input.txt' ";

    struct Process copy[number_of_process];

    // copy the contents into copy structure
    makeCopy(p, copy, number_of_process);

    // call the CPU scheduling technique
    SRTF(p, copy, number_of_process);

    // print the final result
    writeToFile(p, copy, number_of_process);
}

// main function execution begins here
int main()
{
    readFromFile();
    cout << endl;

    return 0;
}
