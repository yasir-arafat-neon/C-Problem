#include <iostream>
#include<vector>
using namespace std;

// Utility function for DFS to detect a cycle in a directed graph
bool isCyclicUtil(vector<vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &recStack)
{
    // If the node is already in the recursion stack, a cycle is detected
    if (recStack[u])
        return true;

    // If the node is already visited and not in recursion stack, no need to check again
    if (visited[u])
        return false;

    // Mark the current node as visited and add it to the recursion stack
    visited[u] = true;
    recStack[u] = true;

    // Recur for all neighbors
    for (int x : adj[u])
    {
        if (isCyclicUtil(adj, x, visited, recStack))
            return true;
    }

    // Remove the node from the recursion stack
    recStack[u] = false;
    return false;
}

// Function to construct an adjacency list from edge list
vector<vector<int>> constructadj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &it : edges)
    {
        adj[it[0]].push_back(it[1]); // Directed edge from it[0] to it[1]
    }
    return adj;
}

// Function to detect cycle in a directed graph
bool isCyclic(int V, vector<vector<int>> &edges)
{
    // Construct the adjacency list
    vector<vector<int>> adj = constructadj(V, edges);

    // visited[] keeps track of visited nodes
    // recStack[] keeps track of nodes in the current recursion stack
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    // Check for cycles starting from every unvisited node
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCyclicUtil(adj, i, visited, recStack))
            return true; // Cycle found
    }

    return false; // No cycles detected
}

int main()
{
   int V = 4;
vector<vector<int>> edges = {
    {0, 1},
    {1, 2},
    {2, 3}
};


    // Output whether the graph contains a cycle
    cout << (isCyclic(V, edges) ? "true" : "false") << endl;

    return 0;
}
