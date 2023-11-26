/*
Print Pattern

GfG Weekly + You = Perfect Sunday Evenings!
Register for free now

banner
Print a sequence of numbers starting with N, without using loop, where replace N with N - 5, until N > 0. After that replace N with N + 5 until N regains its initial value.

Example 1:

Input:
N = 16
Output:
16 11 6 1 -4 1 6 11 16
Explaination:
The value decreases until it is greater than 0. After that it increases and stops when it becomes 16 again.
Example 2:

Input:
N = 10
Output:
10 5 0 5 10
Explaination: It follows the same logic as per the above example.
*/

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    void seqsum(vector<int> &ans, int N, int x)
    {
        if (N <= 0 || N > x)
        {
            ans.push_back(N);
            return;
        }
        ans.push_back(N);
        seqsum(ans, N - 5, x);
        if (N <= x)
        {
            ans.push_back(N);
        }
    }
    vector<int> pattern(int N)
    {
        // code here
        vector<int> ans;
        seqsum(ans, N, N);
        return ans;
    }
};