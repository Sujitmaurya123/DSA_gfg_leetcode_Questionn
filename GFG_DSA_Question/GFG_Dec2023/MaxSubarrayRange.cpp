/*
Number of subarrays with maximum values in given range

Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example 1:

Input :
Arr = {2, 0, 11, 3, 0}
L = 1 and R = 10
Output :
4
Explanation:
The sub-arrays {2}, {2, 0}, {3} and {3, 0} have maximum in range 1-10.
Example 2:

Input :
Arr = {3, 4, 1}
L = 2 and R = 4
Output :
5
Explanation:
The sub-arrays {3}, {3, 4}, {3,4,1}, {4} and {4, 1} have maximum in range 2-4.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long long start = 0, end = 0, result = 0, temp = 0;
        for (long long end = 0; end < n; end++)
        {
            if (a[end] >= L && a[end] <= R)
            {
                temp = end - start + 1;
            }
            if (a[end] > R)
            {
                temp = 0;
                start = end + 1;
            }
            result = result + temp;
        }
        return result;
    }
};