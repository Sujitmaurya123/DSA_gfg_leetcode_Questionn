/*
Candy

There are N children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:

Each child must have atleast one candy.
Children with a higher rating than its neighbors get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute.

Example 1:

Input:
N = 3
ratings = [1, 0, 2]
Output:
5
Explanation:
You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input:
N = 3
ratings = [1, 2, 2]
Output:
4
Explanation:
You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it statisfies the above two conditions.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCandy(int n, vector<int> &ratings)
    {
        // code here
        vector<int> pre(n);

        // Prefix + check left neighbours.
        pre[0] = 1;
        for (int i = 1; i < n; i++)
        {
            // If the ith child has higher rating that neighbour child.
            if (ratings[i] > ratings[i - 1])
            {
                pre[i] = pre[i - 1] + 1;
            }
            else
            {
                pre[i] = 1;
            }
        }

        // Suffix + check right neighbours.
        vector<int> suff(n);
        suff[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                suff[i] = suff[i + 1] + 1;
            }
            else
            {
                suff[i] = 1;
            }
        }

        int min_candies = 0;
        for (int i = 0; i < n; i++)
        {
            min_candies += max(pre[i], suff[i]);
        }
        return min_candies;
    }
};