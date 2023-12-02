/*
Inorder Traversal and BST

Money can’t buy you happiness. But Geekbits can buy you GfG goodies and it’s the same thing. Earn 2X Geekbits Now

banner
Given an array arr of size N, determine whether this array represents an inorder traversal of a BST.

Note: All keys in BST must be unique.

Example 1:

Input:
N = 3
arr = {2, 4, 5}
Output: 1
Explaination:
Given array is inorder traversal for the following tree:
    4
   / \
  2   5
Example 2:

Input:
N = 3
arr = {2, 4, 1}
Output: 0
Explaination:
Given array can not represent any BST.
*/

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        for (int i = 0; i < N - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }
};