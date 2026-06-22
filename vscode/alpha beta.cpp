#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int alphabeta(int depth,int index,bool isMax,vector<int>&values,int alpha,int beta)
{
    if(index >= values.size())
    return 0;

    if(depth == 0)
    return values[index];

    if(isMax)
    {
        int best=INT_MIN;

        for(int i=0;i<2;i++)
        {
            int val=alphabeta(depth-1,index*2+i,false,values,alpha,beta);
            best=max(best,val);
            alpha=max(alpha,best);
            if(alpha >= beta)
                break;
        }
        return best;
    }
    else
    {
        int best=INT_MAX;

        for(int i=0;i<2;i++)
        {
            int val=alphabeta(depth-1,index*2+i,true,values,alpha,beta);
            best=min(best,val);
            beta=min(beta,best);
            if(alpha >= beta)
                break;
        }
        return best;
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

    int depth= log2(n);

    int result= alphabeta(depth,0,true,values,INT_MIN,INT_MAX);

    cout<<"best score= "<<result<<"\n";

    return 0;
}