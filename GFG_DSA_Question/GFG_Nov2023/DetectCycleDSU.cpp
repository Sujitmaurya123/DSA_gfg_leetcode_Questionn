/*
Detect Cycle using DSU


Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

Note: Solve the problem using disjoint set union (DSU).

Example 1:

Input:

Output: 1
Explanation: There is a cycle between 0->2->4->0
Example 2:

Input:

Output: 0
Explanation: The graph doesn't contain any cycle

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int findPar(vector<int> &parent, int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findPar(parent, parent[node]);
    }

    bool unionSet(int i, int j, vector<int> &parent)
    {
        int u = findPar(parent, i);
        int v = findPar(parent, j);

        if (u != v)
        {
            parent[u] = v;
            return false;
        }

        return true;
    }
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                // i<adj[i][j] to handle case for 1->2 and 2->1 not considre as cycle
                if (i < adj[i][j] && unionSet(i, adj[i][j], parent))
                {
                    return 1;
                }
            }
        }

        return 0;
    }
};