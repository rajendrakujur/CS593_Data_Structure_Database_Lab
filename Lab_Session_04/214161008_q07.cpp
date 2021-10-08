/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 08:43*/

#include <iostream>
#include <fstream>
using namespace std;

// stack structure
struct Stack
{
    string data[1000];
    int top;
    int size;
};

// returns true if the stack is full
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

// returns true if the stack is empty
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

// pushes str(string) into the stack
void push(struct Stack &s, string str)
{
    if (!isFull(s))
    {
        s.data[++s.top] = str;
    }
}

// pops an element from the stack and returns if stack is empty returns NULL
string pop(struct Stack &s)
{
    if (!isEmpty(s))
    {
        return s.data[s.top--];
    }
    return "NULL";
}

// returns the simplified path from the given UNIX path
string simplifiedPath(string path)
{
    struct Stack s;
    s.top = -1;
    s.size = 1000;

    int index = 0;
    char directory_name[500];

    // travese path untill it reaches to the end
    while (path[index] != '\0')
    {
        // intialize directory name as /
        directory_name[0] = '/';

        while (path[index] == '/')
        {
            index++;
        }

        // if this / is the last of the given path then break loop
        if (path[index] == '\0')
        {
            break;
        }
        // if we read .. then pop from stack i.e. move to the parent directory
        else if (path[index] == '.' && path[index + 1] == '.')
        {
            pop(s);
            index += 2;
        }
        // if . then don't do anything
        else if (path[index] == '.')
        {
            index += 1;
        }
        // if reading character other than / and . then start storing in the directory name and push onto the stack
        else if (path[index] != '/' || path[index] != '.')
        {
            int directory_index = 1;
            // if it was the end of the string
            while (path[index] != '/')
            {
                if (path[index] == '\0')
                    break;
                directory_name[directory_index++] = path[index];
                index++;
            }
            directory_name[directory_index] = '\0';
            push(s, directory_name);
        }
    }
    // return the top-most
    string simplified_path;

    // create another stack for reversing the path
    struct Stack st;
    st.top = -1;
    st.size = 1000;

    while (!isEmpty(s))
    {
        push(st, pop(s));
    }

    bool current_directory = true;
    while (!isEmpty(st))
    {
        simplified_path += pop(st);
        current_directory = false;
    }
    if (current_directory)
    {
        simplified_path = "/";
    }
    return simplified_path;
}

void readFile()
{
    ifstream fin;
    fin.open("214161008_q07_input.txt");

    ofstream fout;
    fout.open("214161008_q07_output.txt");

    string path;
    while (!fin.eof())
    {
        fin >> path;
        // calls the simplified  path and stores the returned simplified path
        path = simplifiedPath(path);

        fout << path << endl;
    }

    fin.close();
    cout << "\nRead from file '214161008_q07_input.txt'.";
    fout.close();
    cout << "\nWritten to file '214161008_q07_input.txt'.";
}

// main function execution begins here
int main()
{
    readFile();
    cout << endl;
    return 0;
}
