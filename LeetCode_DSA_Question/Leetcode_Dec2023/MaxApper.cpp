/*
1287. Element Appearing More Than 25% In Sorted Array

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.



Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {

        int n = arr.size();
        int y = (n * 25) / 100;

        // MAP KO FILL KAR RAHE HN
        map<int, int> mp;
        for (auto it : arr)
        {
            mp[it]++;
        }

        // array KE ANDAR TRAVERSE KAR RAHE  AUR DEKH RAHE KI ARRAY KA ith ELEMENT KI FREQUENCY MAP KE ANDAR 25% (Y) SE ZADA HAI YA NAHI.
        for (int i = 0; i < n; i++)
        {
            if (mp[arr[i]] > y)
            {
                return arr[i];
            }
        }
        return -1;
    }
};