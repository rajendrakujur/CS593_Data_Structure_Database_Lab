/*Last update by RAJENDRA KUJUR (214161008) on 24-08-2021 at 19:33*/

#include <iostream>
using namespace std;

int matrix[1000][1000];

// return number of peaks in a matrix
int numberOfPeaks(int matrix[][1000], int row, int column)
{
    int total_peaks = 0;

    // traverse matrix
    for (int row_index = 1; row_index < row - 1; row_index++)
    {
        for (int column_index = 0; column_index < column - 1; column_index++)
        {
            // if it matches the all the four conditions then increase the total peaks
            if (matrix[row_index][column_index] > matrix[row_index - 1][column_index - 1])
            {
                if (matrix[row_index][column_index] > matrix[row_index - 1][column_index + 1])
                {
                    if (matrix[row_index][column_index] > matrix[row_index + 1][column_index - 1])
                    {
                        if (matrix[row_index][column_index] > matrix[row_index + 1][column_index + 1])
                        {
                            // cout << matrix[row_index][column_index] << endl;
                            // cout << "\nTotal peaks ++";
                            total_peaks++;
                        }
                    }
                }
            }
        }
    }
    return total_peaks;
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

    // output result
    cout << numberOfPeaks(matrix, row, column) << endl;
    return 0;
}
