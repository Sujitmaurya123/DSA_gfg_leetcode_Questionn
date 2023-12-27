/*
Anti Diagonal Traversal of Matrix

Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.

Example 1:

Input:
N = 2
matrix[][] = 1 2
            3 4
Output:
1 2 3 4
Explanation:
List of anti-diagnoals in order is
{1}, {2, 3}, {4}
Example 2:

Input:
N = 3
matrix[][] = 3 2 3
            4 5 1
            7 8 9
Output:
3 2 4 3 5 7 1 8 9
Explanation:
List of anti-diagnoals in order is
{3}, {2, 4}, {3, 5, 7}, {1, 8}, {9}
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        int col=0,row=0;
        
        while(col<m && row<n){
            int i=col,j=row;
            
            while(i>=0 && j<n){
                ans.push_back(matrix[j][i]);
                i--;
                j++;
            }
            if(col<m-1)col++;
            else row++;
        }
        return ans;
    }
};
