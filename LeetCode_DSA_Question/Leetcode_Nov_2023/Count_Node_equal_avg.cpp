/*
2265. Count Nodes Equal to Average of Subtree

Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.

4
8  5
0 1   6

Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation:
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.

*/

#include<bits/stdc++.h>
using namespace std;


 struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        int result = 0;
        traverse(root, result);
        return result;
    }

private:
    pair<int, int> traverse(TreeNode *node, int &result)
    {
        if (!node)
            return {0, 0};

        auto [left_sum, left_count] = traverse(node->left, result);
        auto [right_sum, right_count] = traverse(node->right, result);

        int curr_sum = node->val + left_sum + right_sum;
        int curr_count = 1 + left_count + right_count;

        if (curr_sum / curr_count == node->val)
            result++;

        return {curr_sum, curr_count};
    }
};