/*
606. Construct String from Binary Tree

Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.



Example 1:


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
Example 2:


Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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
    string tree2str(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "";
        }

        // Step 1: Start with an empty result string
        stringstream result;

        // Step 2: Perform preorder traversal
        preorderTraversal(root, result);

        // Step 3: Return the final result string
        return result.str();
    }

private:
    void preorderTraversal(TreeNode *node, stringstream &result)
    {
        if (node == nullptr)
        {
            return;
        }

        // Step 4: Append the current node's value to the result
        result << node->val;

        // Step 5: Check if the current node has a left child or a right child
        if (node->left != nullptr || node->right != nullptr)
        {

            // Step 6: If there is a left child, add empty parentheses for it
            result << "(";
            preorderTraversal(node->left, result);
            result << ")";
        }

        // Step 7: If there is a right child, process it similarly
        if (node->right != nullptr)
        {
            result << "(";
            preorderTraversal(node->right, result);
            result << ")";
        }

        // Step 8: The recursion will handle all the child nodes
    }
};