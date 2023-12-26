/*Largest rectangular sub-matrix whose sum is 0

Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.

If there are multiple solutions return the rectangle which starts from minimum column index. If you still have multiple solutions return the one having greatest row number. If no such matrix is present return a zero (0) size matrix.

Example 1:

Input: N = 3, M = 3
mat[][] =  1, 2, 3
          -3,-2,-1
           1, 7, 5

Output:  1, 2, 3
        -3,-2,-1

Explanation: This is the largest sub-matrix,
whose sum is 0.
Example 2:

Input: N = 4, M = 4
mat[][] = 9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10

 Output: -6,-7
          8, 7
         -2, 0 
*/

//User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
        int n = a.size(), m = a[0].size();
        int anscol = m, ansrow = n, mxarea = 0, reqheight = -1, reqwidth = -1;
        vector<vector<int>> pre = a;
        
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                pre[i][j] += pre[i][j - 1];
            }
        }
        
        
        for (int col = m - 1; col >= 0; col--)
        {
            for (int j = m - 1; j >= col; j--)
            {
                unordered_map<int, int> mp;
                mp[0] = -1;
                int sum = 0;
                int width = j - col + 1;
                for (int row = 0; row < n; row++)
                {
                    sum += pre[row][j] - pre[row][col] + a[row][col];
                    if (mp.find(sum) != mp.end())
                    {
                        int height = row - mp[sum];
                        int area = height * width;
                        if (area > mxarea || (area == mxarea && (col < anscol or (col == anscol && height > reqheight))))
                        {
                            mxarea = area;
                            reqheight = height;
                            reqwidth = width;
                            ansrow = mp[sum] + 1;
                            anscol = col;
                        }
                    }
                    if (!mp.count(sum))
                        mp[sum] = row;
                }
            }
        }
        if (mxarea == 0) return {{}};
        vector<vector<int>> ans(reqheight, vector<int>(reqwidth));
        for (int i = 0; i < reqheight; i++)
        {
            for (int j = 0; j < reqwidth; j++)
            {
                ans[i][j] = a[ansrow + i][j + anscol];
            }
        }

        return ans;
  }
};
