#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;
using ll = long long;
#define int long long

void Solve()
{
    ll m,n;
    cin>>n>>m;
    vector<pair<ll,ll>> graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    ll source;
    cin>>source;
    vector<ll>dist(n+1,1e18);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    dist[source]=0;
    pq.push({0,source});
    while (!pq.empty())
    {
        auto[cost,node]=pq.top();
        pq.pop();
        if(cost>dist[node])
        {
            continue;
        }
        for(auto[child,weight]: graph[node])
        {
            if(dist[node]+weight<dist[child])
            {
                dist[child]=dist[node]+weight;
                pq.push({dist[child],child});
            }
        }
    }
    cout<<"shortest distance from node "<<source<<":\n";

    for(int i=1;i<=n;i++)
    {
        if(dist[i]==1e18)
        cout<<i<<" :INF\n";
        else
        cout<<i<<" :"<<dist[i]<<"\n";
    }
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}