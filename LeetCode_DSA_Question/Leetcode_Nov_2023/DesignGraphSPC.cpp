/*
2642. Design Graph With Shortest Path Calculator

There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.


Input
["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
[[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
Output
[null, 6, -1, null, 6]

Explanation
Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.

*/

#include<bits/stdc++.h>
using namespace std;


class Graph {
public:
    // Adjacency list to represent the graph
    vector<vector<pair<int, int>>> adjacencyList;

    // Constructor to initialize the graph with nodes and edges
    Graph(int n, vector<std::vector<int>>& edges) {
        adjacencyList.resize(n);
        for (auto edge : edges)
            adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Add a new edge to the graph
    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Find the shortest path between two nodes using Dijkstra's algorithm
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

private:
    // Dijkstra's algorithm to find the shortest path
    int dijkstra(int start, int end) {
        int n = adjacencyList.size();
        vector<int> distances(n, INT_MAX);
        distances[start] = 0;

        // Priority queue to efficiently retrieve the node with the minimum distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, start});

        while (!priorityQueue.empty()) {
            int currentNode = priorityQueue.top().second;
            int currentCost = priorityQueue.top().first;
            priorityQueue.pop();

            // Skip if a shorter path has already been found
            if (currentCost > distances[currentNode])
                continue;

            // If found the target node then return the cost
            if(currentNode == end)
                return currentCost ;

            // Explore neighbors and update distances
            for (auto edge : adjacencyList[currentNode]) {
                int neighbor = edge.first, edgeLength = edge.second;
                int newRouteCost = edgeLength + distances[currentNode];

                // Update distance if a shorter route is found
                if (distances[neighbor] > newRouteCost) {
                    distances[neighbor] = newRouteCost;
                    priorityQueue.push({newRouteCost, neighbor});
                }
            }
        }

        // Return the minimum distance or -1 if no path exists
        return ((distances[end] == INT_MAX) ? -1 : distances[end]);
    }
};
