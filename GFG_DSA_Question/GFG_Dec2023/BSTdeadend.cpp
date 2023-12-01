/*
Check whether BST contains Dead End

Given a Binary Search Tree that contains unique positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means a leaf node, at which no other node can be inserted.

Example 1:

Input :
               8
             /   \
           5      9
         /  \
        2    7
       /
      1

Output :
Yes
Explanation :
Node 1 is a Dead End in the given BST.
Example 2:

Input :
              8
            /   \
           7     10
         /      /   \
        2      9     13

Output :
Yes
Explanation :
Node 9 is a Dead End in the given BST.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node * right, * left;
};

/*You are required to complete below method */
class Solution
{
public:
    bool solve(Node *root, int min, int max)
    {
        if (root == NULL)
        {
            return false;
        }
        if (min == max)
        {
            return true;
        }
        return solve(root->left, min, root->data - 1) || solve(root->right, root->data + 1, max);
    }
    bool isDeadEnd(Node *root)
    {
        // Your code here
        int min = 1;
        int max = INT_MAX;
        return solve(root, min, max);
    }
};