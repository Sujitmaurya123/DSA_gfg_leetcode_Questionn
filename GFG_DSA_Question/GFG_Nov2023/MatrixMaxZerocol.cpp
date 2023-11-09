/*
Predict the Column

Given a matrix(2D array) M of size N*N consisting of 0s and 1s only. The task is to find the column with maximum number of 0s. If more than one column exists, print the one which comes first. If the maximum number of 0s is 0 then return -1.

Example:

Input:
N = 3
M[][] = {{0, 0, 0},
          {1, 0, 1},
          {0, 1, 1}}
Output:
0
Explanation:
0th column (0-based indexing) is having 2 zeros which is maximum among all columns and comes first.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    int columnWithMaxZeros(vector<vector<int>> arr, int N)
    {

        
        int max = 0;
        int ind = 0;
        for (int i = 0; i < N; i++)
        {
            int max2 = 0;
            for (int j = 0; j < N; j++)
            {
                if (arr[j][i] == 0)
                {
                    max2++;
                }
            }

            if (max < max2)
            {
                max = max2;
                ind = i;
            }

            if (max == 0)
                ind = -1;
        }

        return ind;
    }
};