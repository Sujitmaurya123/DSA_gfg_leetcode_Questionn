/*
2849. Determine if a Cell Is Reachable at a Given Time

You are given four integers sx, sy, fx, fy, and a non-negative integer t.

In an infinite 2D grid, you start at the cell (sx, sy). Each second, you must move to any of its adjacent cells.

Return true if you can reach cell (fx, fy) after exactly t seconds, or false otherwise.

A cell's adjacent cells are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.

Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
Output: true
Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above.

Input: sx = 3, sy = 1, fx = 7, fy = 3, t = 3
Output: false
Explanation: Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.


Constraints:

1 <= sx, sy, fx, fy <= 109
0 <= t <= 109
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
    {
        // Calculate the absolute differences in x and y coordinates between the start and target points.
        int xDistance = abs(sx - fx);
        int yDistance = abs(sy - fy);

        // Calculate the minimum Manhattan distance (minimum steps) to reach the target.
        int min_dist = min(xDistance, yDistance) + abs(yDistance - xDistance);

        // If the starting and target cells are the same, check if t is not 1.
        if (min_dist == 0)
        {
            if (t == 1)
            {
                return false; // If t is 1, it's impossible to stay at the same cell for that time, so return false.
            }
            else
            {
                return true; // If t is greater than 1, we can stay at the same cell for t seconds, so return true.
            }
        }

        // If the minimum distance is greater than 0, check if t is greater than or equal to the minimum distance.
        return t >= min_dist; // If t is sufficient to cover the minimum distance, return true; otherwise, return false.
    }
};
