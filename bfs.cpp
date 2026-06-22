#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll=long long;
#define int long long
void Solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>tree[n+1];
    for(int i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<ll>isVisited(n+1,false);
    queue<ll>q;
    q.push(1);
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        if(isVisited[node]) continue;
        isVisited[node]=true;
        cout<<node<<" ";
        for(auto& child:tree[node])
        {
            if(!isVisited[child])
              q.push(child);
        }
    }
}
int32_t main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t=1;
   for(int i=1;i<=t;i++)
   {
      Solve();
   }
   return 0;
}