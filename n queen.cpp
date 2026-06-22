#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int n,int row,int col,vector<string>&board)
{
    for(int j=0;j<n;j++)
    {
        if(board[row][j]=='Q')
        return false;
    }
    for(int i=0;i<n;i++)
    {
        if(board[i][col]=='Q')
        return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        return false;
    }
    for(int i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]=='Q')
        return false;
    }
    return true;
}
void nQueen(int n,int row,vector<string>&board,vector<vector<string>>&ans)
{
    if(n==row)
    {
       ans.push_back(board);
       return;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(n,row,j,board))
        {
            board[row][j]='Q';
            nQueen(n,row+1,board,ans);
            board[row][j]='.';
        }
    }
}
vector<vector<string>>solveNqueen(int n)
{
    vector<string>board(n,string(n,'.'));
    vector<vector<string>>ans;
    nQueen(n,0,board,ans);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<string>>answer=solveNqueen(n);
    for(auto& board:answer)
    {
        for(auto& row:board)
        cout<<row<<endl;
        cout<<endl;
    }
}