/*Last update by RAJENDRA KUJUR (214161008) on 24-08-2021 at 19:13*/

#include <iostream>
using namespace std;

// to store matrix elements
int matrix[100][100];

// struct to store the whether the number is present in that row
struct mat
{
    int number;
    bool present;
};

void commonElements(int matrix[][100], int row, int column)
{
    // declared a structure(mat) array
    struct mat result[column];

    // stores the fist row elements and intialized bool to true
    for (int column_index = 0; column_index < column; column_index++)
    {
        result[column_index].number = matrix[0][column_index];
        result[column_index].present = true;
    }

    int check_number;
    int result_index;

    // start iterating from 2nd row (index =1)
    for (int row_index = 1; row_index < row; row_index++)
    {
        // for each element we have to check
        for (result_index = 0; result_index < column; result_index++)
        {
            // if the current element is already set to true then only check further
            if (result[result_index].present)
            {
                // update present to false and check in the row
                result[result_index].present = false;
                for (int column_index = 0; column_index < column; column_index++)
                {
                    // if element is present then set it to true otherwise it will be false
                    // and won't be checked in upcoming iterations
                    if (result[result_index].number == matrix[row_index][column_index])
                    {
                        result[result_index].present = true;
                        break;
                    }
                }
            }
        }
    }

    // print the common elements
    for (int index = 0; index < column; index++)
    {
        if (result[index].present)
        {
            cout << result[index].number << " ";
        }
    }
    cout << endl;
}

// main function, execution begins
int main()
{
    int row, column;
    cout << "Enter number of rows : ";
    cin >> row;
    cout << "Enter number of columns : ";
    cin >> column;

    // input the matrix in row-major fashion
    for (int row_index = 0; row_index < row; row_index++)
    {
        for (int column_index = 0; column_index < column; column_index++)
        {
            cin >> matrix[row_index][column_index];
        }
    }

    // call the function
    commonElements(matrix, row, column);
    return 0;
}
