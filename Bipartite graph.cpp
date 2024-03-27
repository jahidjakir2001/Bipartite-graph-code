
/*******************************************************
 *   IN THE NAME OF ALLAH  ,  BISMILLAHIR RAHMANIR RAHIM*
 ********************************************************/
/**.....................................আল্লাহ্ ব্যাতিত কোন মাবুদ নাই............................**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1e9+7
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
string s="abcdefghijklmnopqrstuvwxyz";
int dx[]= {-1,1,0,0,-1,-1,1,1};
int dy[]= {0,0,1,-1,-1,1,1,-1};
vector<int>adj[1000];
bool vis[1000];
vector<int>color(10000);
int node,edge,x,y;
bool dfs(int node,int c)
{
    vis[node]=true;
    color[node]=c;
    for(auto u:adj[node])
    {
        if(vis[u]==false)
        {
            if(dfs(u,c^1)==false)
            {
                return false;
            }
            else
            {
                if(color[u]==color[node])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    faster();
    cin>>node>>edge;
    for(int i=1; i<=node; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans=dfs(1,1);
    if(ans==true)
    {
        cout<<"The graph is bipartite"<<endl;
    }
    else
    {
        cout<<"The graph is not bipartite"<<endl;
    }
}

