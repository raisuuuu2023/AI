#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100];
vector<bool> visited;

bool DLS(int node, int goal, int limit)
{
    if(node == goal)
        return true;

    if(limit == 0)
        return false;

    visited[node] = true;

    for(auto child : graph[node])
    {
        if(!visited[child])
        {
            if(DLS(child, goal, limit - 1))
                return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    visited.assign(n + 1, false);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start, goal, limit;
    cin >> start >> goal >> limit;

    if(DLS(start, goal, limit))
        cout << "Goal Found\n";
    else
        cout << "Goal Not Found\n";

    return 0;
}