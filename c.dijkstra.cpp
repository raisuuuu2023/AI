#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> graph(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, 1e18);
    vector<int> parent(n + 1, -1);

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if(cost > dist[node])
            continue;

        for(auto [child, weight] : graph[node])
        {
            if(dist[node] + weight < dist[child])
            {
                dist[child] = dist[node] + weight;
                parent[child] = node;

                pq.push({dist[child], child});
            }
        }
    }

    if(dist[n] == 1e18)
    {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> path;

    int cur = n;

    while(cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    for(int node : path)
        cout << node << " ";

    cout << '\n';

    return 0;
}