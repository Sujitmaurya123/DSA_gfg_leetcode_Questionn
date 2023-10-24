/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

1
3 2
5 3 9

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]

*/

#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int size = q.size();
            int maxi = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                maxi = max(maxi, node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};