/*
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
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
    void iorder(vector<int> &ans, TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        iorder(ans, root->left);
        ans.push_back(root->val);
        iorder(ans, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        iorder(ans, root);
        return ans;
    }
};