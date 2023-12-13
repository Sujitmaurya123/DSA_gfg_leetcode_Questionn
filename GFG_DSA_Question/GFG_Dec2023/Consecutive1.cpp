/*
Consecutive 1's not allowed

Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

Example 1:

Input:
N = 3
Output: 5
Explanation:
5 strings are (000,
001, 010, 100, 101).
Example 2:

Input:
N = 2
Output: 3
Explanation:
3 strings are (00,01,10).
*/

// User function template for C++
#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Solution
{
public:
    // #define ll long long
    ll countStrings(int n)
    {
        // code here

        ll int zeroending = 1;
        ll int oneending = 1;
        ll int sum = zeroending + oneending;

        if (n == 1)
            return sum;

        int i = 2;
        while (i <= n)
        {

            oneending = zeroending;
            zeroending = sum;

            sum = (oneending + zeroending) % 1000000007;
            i++;
        }

        return sum % 1000000007;
    }
};