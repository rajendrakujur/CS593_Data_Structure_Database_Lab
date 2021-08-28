/*Last update by RAJENDRA KUJUR (214161008) on 27-08-2021 at 20:30*/

#include <iostream>
using namespace std;

bool matrix[100][100];

// stack structure
struct stack
{
    int data[1000];
    int top;
    int size;
};

// returns true if stack is full, else returns false
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

// returns true if stack is empty, else returns false
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

// pushes the ch character in stack
void push(struct stack &s, int number)
{
    if (!isFull(s))
    {
        s.data[++s.top] = number;
    }
}

// returns top element from stack
int top(struct stack s)
{
    return s.data[s.top];
}

// pops the top element from the stack and returns char
int pop(struct stack &s)
{
    if (!isEmpty(s))
    {
        return s.data[s.top--];
    }
    else
    {
        return -1;
    }
}

// takes histogram for a row and returns maximum area for it
int maxAreaHistogram(int array[], int size)
{
    // to store left and right limit for that particular column
    int left_limits[size];
    int right_limits[size];

    // stack declaration
    struct stack s;
    s.top = -1;
    s.size = 100;

    // filling left limits
    for (int column_index = 0; column_index < size; ++column_index)
    {
        // if stack is empty left limit will for that column_index and push its index into stack
        if (isEmpty(s))
        {
            left_limits[column_index] = 0;
            push(s, column_index);
        }
        // else keep popping the elements till we get value lower than array[column_index]]
        else
        {
            while (!isEmpty(s) && array[top(s)] >= array[column_index])
            {
                pop(s);
            }
            // update if stack is empty assign to minimum possible(0) or just after the index of lower height
            left_limits[column_index] = isEmpty(s) ? 0 : top(s) + 1;
            push(s, column_index);
        }
    }

    // clearing stack
    while (!isEmpty(s))
    {
        pop(s);
    }

    // filling right limits
    for (int column_index = size - 1; column_index >= 0; column_index--)
    {
        // if stack is empty right limit will for that column_index and push its index into stack
        if (isEmpty(s))
        {
            right_limits[column_index] = size - 1;
            push(s, column_index);
        }
        // else keep popping the elements till we get value lower than array[column_index]]
        else
        {
            while (!isEmpty(s) && array[top(s)] >= array[column_index])
            {
                pop(s);
            }
            // update if stack is empty assign to maximum possible(size-1) or just before the index of lower height
            right_limits[column_index] = isEmpty(s) ? size - 1 : top(s) - 1;
            push(s, column_index);
        }
    }

    int maximum_area = 0;
    // calculate area for each column number and if it is greater than already existing then update maximum area
    for (int column_index = size - 1; column_index >= 0; column_index--)
    {
        maximum_area = max(maximum_area, array[column_index] * (right_limits[column_index] - left_limits[column_index] + 1));
    }
    return maximum_area;
}

int maxSizeRectangle(bool matrix[][100], int rows, int columns)
{
    // if the original matrix has 0 rows and columns then return 0 directly
    if (rows == 0 || columns == 0)
        return 0;

    // to copy original matrix into an int matrix so that we can update it according to need
    int matrix_int[rows][columns];

    // copy the original matrix
    for (int row_index = 0; row_index < rows; row_index++)
    {
        for (int column_index = 0; column_index < columns; column_index++)
        {
            matrix_int[row_index][column_index] = matrix[row_index][column_index];
        }
    }

    // current maximum histogram for 0th row
    int current_maximum = maxAreaHistogram(matrix_int[0], columns);

    // update the matrix_int after reading for every 1 in the original matrix
    for (int row_index = 1; row_index < rows; row_index++)
    {
        for (int column_index = 0; column_index < columns; column_index++)
        {
            if (matrix_int[row_index - 1][column_index] != 0 && matrix_int[row_index][column_index] == 1)
            {
                matrix_int[row_index][column_index] = 1 + matrix_int[row_index - 1][column_index];
            }
        }

        // store the maximum area for that particular row in new_value
        int new_value = maxAreaHistogram(matrix_int[row_index], columns);

        // if new_value is greater than previous area then update
        if (current_maximum < new_value)
        {
            current_maximum = new_value;
        }
    }
    // returns the max area (size of rectangle)
    return current_maximum;
}

int main()
{
    int rows, columns;
    cout << "Enter number of rows  : ";
    cin >> rows;
    cout << "Enter number of columns : ";
    cin >> columns;

    // take inputs from the user
    cout << "Enter matrix elements (0 or 1): ";
    for (int row_index = 0; row_index < rows; row_index++)
    {
        for (int column_index = 0; column_index < columns; column_index++)
        {
            cin >> matrix[row_index][column_index];
        }
    }

    cout << maxSizeRectangle(matrix, rows, columns) << endl;
    return 0;
}