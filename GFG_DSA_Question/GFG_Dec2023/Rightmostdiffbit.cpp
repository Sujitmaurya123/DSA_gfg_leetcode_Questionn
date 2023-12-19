/*
Rightmost different bit

Given two numbers M and N. The task is to find the position of the rightmost different bit in the binary representation of numbers. If both M and N are the same then return -1 in this case.

Example 1:

Input:
M = 11, N = 9
Output:
2
Explanation:
Binary representation of the given numbers are: 1011 and 1001, 2nd bit from right is different.
Example 2:

Input:
M = 52, N = 4
Output:
5
Explanation:
Binary representation of the given numbers are: 110100 and 0100, 5th-bit from right is different.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        // if(m==n)return -1;
        // int ans=1;
        // while(m>0 || n>0){
        //     if((m&1)!=(n&1)){
        //         return ans;
        //     }
        //     m=m>>1;
        //     n=n>>1;
        //     ans++;
        // }
        // return ans;

        if (m == n)
            return -1;
        int ans = 1;
        int num = m ^ n;
        while (num > 0)
        {
            if ((num & 1))
                return ans;
            num = num >> 1;
            ans++;
        }
        return ans;
    }
};