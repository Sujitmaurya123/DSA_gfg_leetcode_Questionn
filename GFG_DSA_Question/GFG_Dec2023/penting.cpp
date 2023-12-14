/*
Painting the Fence

Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colors. Since the answer can be large return it modulo 109 + 7.

Example 1:

Input:
n = 3
k = 2
Output: 6
Explanation:
We have following possible combinations:



Example 2:

Input:
n = 2
k = 4
Output: 16
Explanation:
After coloring first post with
4 possible combinations, you can still color
next posts with all 4 colors. Total possible
combinations will be 4x4=16
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int n, int k)
    {
        // code here
        vector<long long> dp(n + 1, 0);
        long long mod = 1000000007;
        dp[0] = 0;
        dp[1] = k % mod;
        dp[2] = ((k % mod) * (k % mod)) % mod;
        for (long long i = 3; i <= n; i++)
        {
            dp[i] = (((dp[i - 1] + dp[i - 2]) % mod) * (k - 1) % mod) % mod;
        }
        return dp[n];
    }
};