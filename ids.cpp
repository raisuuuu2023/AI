#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
#define int long long

vector<ll> graph[100005];
bool found=false;

void DLS(ll node,ll goal, ll depth)
{
    if(depth<0 || found) return;

    cout<<node<<" ";

    if(node==goal)
    {
        cout<<"\nFound node "<<goal<<"\n";
        found=true;
        return;
    }
    for(auto child:graph[node])
    {
        DLS(child,goal,depth-1);
    }
}

void IDS(ll start,ll goal, ll maxdepth)
{
    for(ll d=0;d<=maxdepth;d++)
    {
        found=false;
        
        cout<<"\nDepth limit="<<d<<"\n";

        DLS(start,goal,d);

        cout<<"\n";
        if(found) return;
    }
    cout<<"goal not found\n";
}

int32_t main()
{
    ll n, m;
    cin >> n >> m;
    
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll start,goal;
    cin>>start>>goal;

    IDS(start,goal,n);

    return 0;
}