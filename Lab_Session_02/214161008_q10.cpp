/*Last update by RAJENDRA KUJUR (214161008) on 27-08-2021 at 23:15*/

#include <iostream>
using namespace std;

bool matrix[1000][1000];

// change the matrix and prints it
void setZero(bool matrix[][1000], int row, int column)
{
    // zeroth row zeroth column is set to true for preventing the conflicting of updating matrix[0][column-1] and matrix[row-1][0]
    int column_zero = 1;

    for (int row_index = 0; row_index < row; row_index++)
    {
        // update the matrix element to 0 if we encouter the element to be 0
        if (matrix[row_index][0] == 0)
        {
            column_zero = 0;
        }
        for (int column_index = 0; column_index < column; column_index++)
        {
            // for every zero we encounter update the zeroth row and zeroth column as 0
            if (matrix[row_index][column_index] == 0)
            {
                matrix[row_index][0] = 0;
                matrix[0][column_index] = 0;
            }
        }
    }

    // start traversing backside
    for (int row_index = row - 1; row_index >= 0; row_index--)
    {
        for (int column_index = column - 1; column_index >= 0; column_index--)
        {
            // if any of the zeroth row or zeroth column has 0 in the respective column and row index
            // then update current element to 0
            if (matrix[row_index][0] == 0 || matrix[0][column_index] == 0)
            {
                matrix[row_index][column_index] = 0;
            }
        }
        //
        if (column_zero = 0)
        {
            matrix[row_index][0] = 0;
        }
    }

    // print final result
    for (int row_index = row - 1; row_index >= 0; row_index--)
    {
        for (int column_index = column - 1; column_index >= 0; column_index--)
        {
            cout << matrix[row_index][column_index] << " ";
        }
        cout << endl;
    }
}

// main function execution begins here
int main()
{
    int row, column;
    cout << "Enter number of rows : ";
    cin >> row;
    cout << "Enter number of columns : ";
    cin >> column;

    // take input from user
    for (int row_index = 0; row_index < row; row_index++)
    {
        for (int column_index = 0; column_index < column; column_index++)
        {
            cin >> matrix[row_index][column_index];
        }
    }

    // call the function
    setZero(matrix, row, column);
    return 0;
}
