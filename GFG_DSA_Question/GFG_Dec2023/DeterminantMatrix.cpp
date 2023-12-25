/*
Determinant of a Matrix



Given a square matrix of size n *n.The task is to find the determinant of this matrix.

    Example 1 :

    Input : n = 4 matrix[][] = {{1, 0, 2, -1},
                                {3, 0, 0, 5},
                                {2, 1, 4, -3},
                                {1, 0, 5, 0}} Output : 30 Explanation : Determinant of the given matrix is 30. Example 2 :

    Input : n = 3 matrix[][] = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 10, 9}} Output : 12 Explanation : Determinant of the given matrix is 12.
 */
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function for finding determinant of matrix
    int determinantOfMatrix(vector<vector<int>> mat, int n)
    {
        // Base case: if the matrix is 1x1
        if (n == 1)
        {
            return mat[0][0];
        }

        // Base case: if the matrix is 2x2
        if (n == 2)
        {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        }

        int det = 0; // Initialize determinant

        // Iterate over the first row to expand along the first row
        for (int i = 0; i < n; i++)
        {
            // Calculate the cofactor
            int cofactor = (int)pow(-1, i) * mat[0][i] * determinantOfMatrix(subMatrix(mat, 0, i), n - 1);

            // Add the cofactor to the determinant
            det += cofactor;
        }

        return det;
    }

    // Function to calculate the submatrix by excluding the given row and column
    vector<vector<int>> subMatrix(vector<vector<int>> mat, int r, int c)
    {
        int n = mat.size();
        vector<vector<int>> arr(n - 1, vector<int>(n - 1, 0));
        int row = 0, col = 0;

        // Iterate over the rows of the original matrix
        for (int i = 0; i < n; i++)
        {
            // Skip the specified row
            if (i != r)
            {
                // Iterate over the columns of the original matrix
                for (int j = 0; j < n; j++)
                {
                    // Skip the specified column
                    if (j != c)
                    {
                        // Copy the element to the submatrix
                        arr[row][col] = mat[i][j];
                        col++;
                    }
                }

                col = 0;
                row++;
            }
        }

        return arr;
    }
};