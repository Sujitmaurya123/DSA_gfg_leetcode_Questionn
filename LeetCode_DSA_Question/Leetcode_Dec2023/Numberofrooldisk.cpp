/*  
1155. Number of Dice Rolls With Target Sum

You have n dice, and each die has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
 
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = (int)pow(10, 9) + 7; // Modulo value for calculations

    // Function to calculate the number of ways to obtain a target sum using 'n' dice rolls with 'k' faces on each die
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // Create a 2D vector for memoization
        return recursion(dp, n, k, target); // Call the recursive function with memoization
    }

private:
    // Recursive function to calculate the number of ways to obtain the target sum
    int recursion(vector<vector<int>>& dp, int n, int k, int target) {
        // Base cases: if the target sum is reached with 'n' dice rolls or if 'n' becomes 0 or target reaches 0, return accordingly
        if (target == 0 && n == 0) return 1;
        if (n == 0 || target <= 0) return 0;

        // If the result is already computed, return the stored value from the memoization table
        if (dp[n][target] != -1) return dp[n][target] % mod;

        int ways = 0; // Variable to count the number of ways to obtain the target sum
        for (int i = 1; i <= k; i++) {
            // Calculate the number of ways by considering each possible face value of the die
            ways = (ways + recursion(dp, n - 1, k, target - i)) % mod;
        }
        dp[n][target] = ways % mod; // Store the computed result in the memoization table
        return dp[n][target];
    }
};


