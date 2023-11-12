/*
815. Bus Routes

You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.



Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
*/
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
        {
            return 0;
        }

        int maxStop = -1;
        for (const auto &route : routes)
        {
            for (int stop : route)
            {
                maxStop = max(maxStop, stop);
            }
        }

        if (maxStop < target)
        {
            return -1;
        }

        int n = routes.size();
        vector<int> minBusesToReach(maxStop + 1, INT_MAX);
        minBusesToReach[source] = 0;

        bool flag = true;
        while (flag)
        {
            flag = false;
            for (const auto &route : routes)
            {
                int min = n + 1;
                for (int stop : route)
                {
                    min = std::min(min, minBusesToReach[stop]);
                }
                min++;
                for (int stop : route)
                {
                    if (minBusesToReach[stop] > min)
                    {
                        minBusesToReach[stop] = min;
                        flag = true;
                    }
                }
            }
        }

        return (minBusesToReach[target] < n + 1) ? minBusesToReach[target] : -1;
    }
};