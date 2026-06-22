#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minimax(int depth,bool isMax,vector<int>&values,int index)
{
    if(index>=values.size()) return 0;

    if(depth==0) return values[index];

    if(isMax)
    {
        int res=INT_MIN;

        for(int i=0;i<2;i++)
        {
            int val=minimax(depth-1,false,values,index*2+i);
            res=max(res,val);
        }
        return res;
    }
    else
    {
        int res=INT_MAX;
        for(int i=0;i<2;i++)
        {
            int val=minimax(depth-1,true,values,index*2+i);
            res=min(res,val);
        }
        return res;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>values(n);
    for(int i=0;i<n;i++)
    {
        cin>>values[i];
    }

    int depth=log2(n);

    int result=minimax(depth,true,values,0);
    cout<<result<<"\n";
    return 0;
}