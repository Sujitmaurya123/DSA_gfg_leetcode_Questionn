/*
Max Sum without Adjacents

Given an array Arr of size N containing positive integers. Find the maximum sum of a any possible subsequence such that no two numbers in the subsequence should be adjacent in Arr.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous subsequence with maximum
sum.
*/

// User function template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        if (n == 1)
        {
            return arr[0];
        }
        int a = arr[0];
        int b = max(a, arr[1]);
        for (int i = 2; i < n; i++)
        {
            int c = max(b, a + arr[i]);
            a = b;
            b = c;
        }
        return b;
    }
};