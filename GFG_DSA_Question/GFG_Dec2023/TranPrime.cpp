/*
Transform to prime

Given an array of n integers. Find the minimum non-negative number to be inserted in array, so that sum of all elements of array becomes prime.

Example 1:

Input:
N=5
arr = {2, 4, 6, 8, 12}
Output:
5
Explanation:
The sum of the array is 32 ,we can add 5 to this to make it 37 which is a prime number.
Example 2:

Input:
N=3
arr = {1, 5, 7}
Output:
0
Explanation:
The sum of the array is 13 which is already prime.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPrime(int num)
    {
        if (num < 2)
        {
            return false;
        }
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int minNumber(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = arr[i] + sum;
        }
        if (isPrime(sum))
        {
            return 0;
        }
        for (int i = 1; i < sum; i++)
        {
            if (isPrime(sum + i))
            {
                return i;
            }
        }
    }
};