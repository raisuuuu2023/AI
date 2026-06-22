#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
#define int long long

vector<ll> visited;
vector<ll> tree[100005];
void DFS(ll node)
{
    visited[node]=true;
    cout<<node<<" ";
    for(auto child:tree[node])
    {
        if(!visited[child])
        DFS(child);
    }
}
void Solve()
{
    ll n, m;
    cin>>n>>m;
    visited.assign(n+1,false);
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS(1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}