#include <iostream>
using namespace std;

int matrix[1000][1000];

void printSpiral(int matrix[][1000], int row, int column)
{
    int row_index;
    int column_index;
    for (row_index = 0; row_index < row; row_index++)
    {
        for (column_index = 0; column_index < column; column_index++)
        {
            cout << matrix[row_index][column_index] << " ";
        }
        cout << endl;
    }

    int right_limit = column;
    int left_limit = -1;
    int up_limit = -1;
    int bottom_limit = row;

    while ((left_limit != right_limit) || (up_limit != bottom_limit))
    {
        for (column_index = left_limit + 1; column_index < right_limit; column_index++)
        {
            cout << matrix[up_limit + 1][column_index] << " ";
        }
        up_limit++;
        for (row_index = up_limit + 1; row_index < bottom_limit; row_index++)
        {
            cout << matrix[row_index][right_limit - 1] << " ";
        }
        right_limit--;
        for (column_index = right_limit - 1; column_index > left_limit; column_index--)
        {
            cout << matrix[bottom_limit - 1][column_index] << " ";
        }
        bottom_limit--;
        for (row_index = bottom_limit - 1; row_index > up_limit; row_index--)
        {
            cout << matrix[row_index][left_limit + 1] << " ";
        }
        left_limit++;
    }
    cout << endl;
}

int main()
{
    int row, column;
    cout << "Enter number of rows : ";
    cin >> row;
    cout << "Enter number of columns : ";
    cin >> column;

    for (int row_index = 0; row_index < row; row_index++)
    {
        for (int column_index = 0; column_index < column; column_index++)
        {
            cin >> matrix[row_index][column_index];
        }
    }

    printSpiral(matrix, row, column);
    return 0;
}
