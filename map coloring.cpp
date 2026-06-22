#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int c)
{
    for(int neighbor : graph[node])
    {
        if(color[neighbor] == c)
            return false;
    }
    return true;
}

bool solve(int node, int n, int m,
           vector<vector<int>>& graph,
           vector<int>& color)
{
    if(node == n)
        return true;

    for(int c = 1; c <= m; c++)
    {
        if(isSafe(node, graph, color, c))
        {
            color[node] = c;

            if(solve(node + 1, n, m, graph, color))
                return true;

            color[node] = 0; // backtrack
        }
    }

    return false;
}

int main()
{
    int n = 4; // regions
    int m = 3; // colors

    vector<vector<int>> graph(n);

    // map connections
    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0, 3};
    graph[3] = {1, 2};

    vector<int> color(n, 0);

    if(solve(0, n, m, graph, color))
    {
        cout << "Map Coloring Possible\n\n";

        for(int i = 0; i < n; i++)
        {
            cout << "Region " << i << " -> Color " << color[i] << "\n";
        }
    }
    else
    {
        cout << "Not Possible with given colors\n";
    }

    return 0;
}