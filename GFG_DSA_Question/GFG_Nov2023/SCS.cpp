/*
Shortest Common Supersequence


Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.
*/

#include<bits/stdc++.h>
using namespace std;

// User function template for C++

class Solution
{
public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // code here
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (X[i] == Y[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return (m + n - dp[m][n]);
    }
};