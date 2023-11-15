// User function Template for C++

/*

Better String



Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences.
Example 2:

Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string s)
    {
        unordered_map<char, int> m;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            char ch = s[i - 1];
            dp[i] = 2 * dp[i - 1];
            if (m.find(ch) != m.end())
            {
                int ind = m[ch];
                dp[i] -= dp[ind - 1];
            }
            m[ch] = i;
        }
        return dp[n];
    }

public:
    string betterString(string str1, string str2)
    {
        // code here
        int a = solve(str1);
        int b = solve(str2);
        if (a >= b)
            return str1;
        else
            return str2;
    }
};