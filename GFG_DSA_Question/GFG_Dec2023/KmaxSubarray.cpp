/*
Max Sum Subarray of size K

Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

NOTE*: A subarray is a contiguous part of any given array.

Example 1:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
Example 2:

Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3 + Arr4 =1000,
which is maximum.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        // code here
        long arr_sum = 0;
        long Max_sum;
        for (int i = 0; i < K; i++)
        {
            arr_sum += Arr[i];
            Max_sum = arr_sum;
        }
        for (int i = K; i < N; i++)
        {
            arr_sum += (Arr[i] - Arr[i - K]);
            Max_sum = max(Max_sum, arr_sum);
        }
        return Max_sum;
    }
};