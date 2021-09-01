/*Last update by RAJENDRA KUJUR (214161008) on 24-08-2021 at 20:45*/

#include <iostream>
using namespace std;

int matrix[1000][1000];

// function that prints the matrix in spiral order
void printSpiral(int matrix[][1000], int row, int column)
{
    int row_index;
    int column_index;

    // make arrangement accordingly to the right,left,up,bottom limits
    // right limit to know till how much index we can traverse
    int right_limit = column;
    // left limit to know till how much index we can traverse
    int left_limit = -1;
    // up limit to know till how much index we can traverse
    int up_limit = -1;
    // bottom limit to know till how much index we can traverse
    int bottom_limit = row;
    int count = 0;
    // if left-limit == right_limit or up_limit == bottom_limit means we have traversed the entire matrix
    while (count < (row * column))
    {
        // traverse right (in the topmost row which isn't traversed)
        for (column_index = left_limit + 1; column_index < right_limit; column_index++)
        {
            cout << matrix[up_limit + 1][column_index] << " ";
            count++;
        }
        // since the row has been traversed so increase upper limit(magnitude)
        up_limit++;

        // traverse bottom
        for (row_index = up_limit + 1; row_index < bottom_limit; row_index++)
        {
            cout << matrix[row_index][right_limit - 1] << " ";
            count++;
        }
        // since the right side column has been traversed so decrease right_limit
        right_limit--;

        // traverse left (in the bottom most row which isn't traversed)
        for (column_index = right_limit - 1; column_index > left_limit; column_index--)
        {
            cout << matrix[bottom_limit - 1][column_index] << " ";
            count++;
        }
        // since row has been traversed so decrease bottom_limit
        bottom_limit--;

        // traverse up
        for (row_index = bottom_limit - 1; row_index > up_limit; row_index--)
        {
            cout << matrix[row_index][left_limit + 1] << " ";
            count++;
        }
        // since left column has been traversed so increase left limit
        left_limit++;
    }
    cout << endl;
}

// main function execution begins here
int main()
{
    int row, column;
    cout << "Enter number of rows : ";
    cin >> row;
    cout << "Enter number of columns : ";
    cin >> column;

    // enter matrix elements here
    for (int row_index = 0; row_index < row; row_index++)
    {
        for (int column_index = 0; column_index < column; column_index++)
        {
            cin >> matrix[row_index][column_index];
        }
    }

    // call the function
    printSpiral(matrix, row, column);
    return 0;
}
