/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 08:43*/

#include <iostream>
using namespace std;

// stack structure
struct stack
{
    string data[1000];
    int top;
    int size;
};

// returns true if the stack is full
bool isFull(struct stack s)
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
bool isEmpty(struct stack s)
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
void push(struct stack &s, string str)
{
    if (!isFull(s))
    {
        s.data[++s.top] = str;
    }
}

// pops an element from the stack and returns if stack is empty returns NULL
string pop(struct stack &s)
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
    struct stack s;
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
            while (path[index] != '/')
            {
                directory_name[directory_index++] = path[index];
                index++;
            }
            directory_name[directory_index] = '\0';
            push(s, directory_name);
        }
    }
    // return the top-most
    return pop(s);
}

// main function execution begins here
int main()
{
    string path;
    cout << "Enter path : ";
    cin >> path;

    // calls the simplified  path and stores the returned simplified path
    path = simplifiedPath(path);

    cout << "\nSimplified Path : " << path << endl;
    return 0;
}
