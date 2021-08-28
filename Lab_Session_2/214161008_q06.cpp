/*Last update by RAJENDRA KUJUR (214161008) on 24-08-2021 at 19:21*/

#include <iostream>
using namespace std;

// to store matrix
int matrix[10][10];

// function that prints the 90 degree right rotated matrix
void rotateClockwise(int matrix[][10], int row, int column)
{

    int new_row = column;
    int new_column = row;
    // create a new matrix of column*row order since the original matrix is of row*column order
    int new_matrix[new_row][new_column];

    // at new_matrix[row_index][column_index] this assignment provides 90 degree rotation clockwise
    for (int row_index = 0; row_index < new_row; row_index++)
    {
        for (int column_index = 0; column_index < new_column; column_index++)
        {
            // new_matrix[row_index][column_index] this assignment provides 90 degree rotation clockwise
            new_matrix[row_index][column_index] = matrix[row - column_index - 1][row_index];
        }
    }

    // print the matrix
    for (int row_index = 0; row_index < new_row; row_index++)
    {
        for (int column_index = 0; column_index < new_column; column_index++)
        {
            cout << new_matrix[row_index][column_index] << " ";
        }
        cout << endl;
    }
}

// main function, execution begins here
int main()
{
    int row, column;
    cout << "Enter number of rows : ";
    cin >> row;
    cout << "Enter number of columns : ";
    cin >> column;

    // input the matrix
    for (int row_index = 0; row_index < row; row_index++)
    {
        for (int column_index = 0; column_index < column; column_index++)
        {
            cin >> matrix[row_index][column_index];
        }
    }

    // call the function
    rotateClockwise(matrix, row, column);
    return 0;
}