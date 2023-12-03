/*
Brothers From Different Roots

Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8
BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18
x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /
1
x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)
*/

// User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int countPairs(Node *root1, Node *root2, int x)
    {
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);

        int i = 0;
        int j = v2.size() - 1;

        int c = 0;
        while (i < v1.size() and j >= 0)
        {
            if (v1[i] + v2[j] == x)
            {
                c++;
                i++;
                j--;
            }
            else if (v1[i] + v2[j] > x)
                j--;
            else
                i++;
        }
        return c;
    }
};