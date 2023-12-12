/*
Gold Mine Problem

For the first time ever: GATE 2024 introduces DS & AI in its renowned exam. Take its first ever All India Mock Test

banner
Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect until he can no longer move.

Example 1:

Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination:
The path is {(1,0) -> (2,1) -> (2,2)}.

Example 2:

Input: n = 4, m = 4
M = {{1, 3, 1, 5},
     {2, 2, 4, 1},
     {5, 0, 2, 3},
     {0, 6, 1, 2}};
Output: 16
Explaination:
The path is {(2,0) -> (3,1) -> (2,2)
-> (2,3)} or {(2,0) -> (1,1) -> (1,2)
-> (0,3)}.
*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here

        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            dp[i][m - 1] = M[i][m - 1];
        }

        for (int j = m - 2; j > -1; j--)
        {
            for (int i = 0; i < n; i++)
            {
                dp[i][j] = dp[i][j + 1];

                if (i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                if (i < n - 1)
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1]);

                dp[i][j] += M[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i][0]);

        return ans;
    }
};