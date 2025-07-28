#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of vertices
int graph[MAX][MAX]; // Adjacency matrix
bool visited[MAX];

bool dfs(int v, int parent, int n) {
    visited[v] = true;

    for (int u = 0; u < n; u++) {
        if (graph[v][u]) { // There is an edge from v to u
            if (!visited[u]) {
                if (dfs(u, v, n))
                    return true;
            } else if (u != parent) {
                return true; // Found a back edge (cycle)
            }
        }
    }

    return false;
}

bool isCyclic(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n))
                return true;
        }
    }

    return false;
}

int main() {
    int n = 5; // Number of vertices
    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    // Add edges (undirected)
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][0] = graph[0][2] = 1;
    graph[3][4] = graph[4][3] = 1;

    if (isCyclic(n))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";

    return 0;
}
