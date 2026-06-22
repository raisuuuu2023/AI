#include <iostream>
#include <vector>
#include <queue>

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
        int a, b;
        ll c;

        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    const ll INF = 1e18;

    vector<ll> dist(n + 1, INF);

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
                pq.push({dist[child], child});
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n";

    return 0;
}