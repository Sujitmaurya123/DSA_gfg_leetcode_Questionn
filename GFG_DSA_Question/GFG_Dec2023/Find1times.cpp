/*
How Many X's?

Given two integers L, R, and digit X. Find the number of occurrences of X in all the numbers in the range (L, R) excluding L and R.

Example 1:

Input:
L=10, R=19, X=1
Output:
9
Explanation:
There are 9 1s (11, 12, 13, 14, 15, 16, 17, 18) in the numbers in the range (10,19).
Example 2:

Input:
L=18, R=81, X=9
Output:
7
Explanation:
There are 7 occurrences of the digit 9 in the numbers in the range (18,81).
*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countX(int L, int R, int X)
    {
        // code here
        int temp, count = 0;
        while (L + 1 < R)
        {

            temp = L + 1;
            while (temp > 0)
            {
                if (temp % 10 == X)
                {
                    count++;
                }

                temp = temp / 10;
            }

            L++;
        }

        return count;
    }
};