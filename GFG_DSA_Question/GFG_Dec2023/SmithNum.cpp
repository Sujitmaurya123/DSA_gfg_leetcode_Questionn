/*
Smith Number

Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite number whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.
Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smithNum(int n)
    {
        // code here
        int arr[n + 1] = {0};
        int sum[n + 1] = {0};
        // Sum of the digits of number
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            while (j > 0)
            {
                sum[i] += j % 10;
                j /= 10;
            }
        }
        // greatest prime factor for each number
        for (int i = 2; i <= n; i++)
        {
            if (arr[i] != 0)
                continue;
            arr[i] = i;
            for (int j = 2 * i; j <= n; j += i)
            {
                arr[j] = i;
            }
        }

        int x = n;
        int factorSum = 0;
        while (arr[x] > 0)
        {
            factorSum += sum[arr[x]];
            x = x / arr[x];
        }

        if (arr[n] == n)
            factorSum = 0;

        return factorSum == sum[n];
    }
};