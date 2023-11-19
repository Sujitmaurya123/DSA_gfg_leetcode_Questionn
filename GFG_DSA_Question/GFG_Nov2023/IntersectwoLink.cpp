/*
Intersection of two sorted Linked lists

Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Example 1:

Input:
LinkedList1 = 1->2->3->4->6
LinkedList2 = 2->4->6->8
Output: 2 4 6
Explanation: For the given two
linked list, 2, 4 and 6 are the elements
in the intersection.
Example 2:

Input:
LinkedList1 = 10->20->40->50
LinkedList2 = 15->40
Output: 40
*/

// The structure of the Linked list Node is as follows:


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};


class Solution
{
public:
    Node *findIntersection(Node *t1, Node *t2)
    {
        // code goes here.
        Node *t = new Node(-1);
        Node *temp = t;
        while (t1 && t2)
        {
            if (t1->data == t2->data)
            {
                Node *n = new Node(t1->data);
                temp->next = n;
                temp = n;
                t1 = t1->next;
                t2 = t2->next;
            }
            else if (t1->data < t2->data)
            {
                t1 = t1->next;
            }
            else
            {
                t2 = t2->next;
            }
        }
        temp->next = NULL;
        return t->next;
    }
};