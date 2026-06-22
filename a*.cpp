#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll=long long;
#define int long long

void Solve()
{
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> graph[n+1];
    for(int i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    ll start,goal;
    cin>>start>>goal;
    vector<ll>h(n+1);
    for(int i=1;i<=n;i++)
      cin>>h[i];

    vector<ll>dist(n+1,1e18);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    dist[start]=0;
    pq.push({h[start],start});

    while(!pq.empty())
    {
        auto [f,node]=pq.top();
        pq.pop();

        if(f!=dist[node]+h[node]) continue;
    
        if(node==goal)
        {
            cout<<"shortest cost= "<<dist[node]<<"\n";
            return;
        }
        for(auto[child,weight]:graph[node])
        {
            if(dist[node]+weight<dist[child])
            {
                dist[child]=dist[node]+weight;
                ll new_f= dist[child]+h[child];
                pq.push({new_f, child});
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}