//利用并查集的思想构造成一个集合
//再用01背包取最值
#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int>&p)
{
    if(p[x]!=x)p[x]=find(p[x],p);
    return p[x];
}
void solve()
{
    int n,m,w;
    cin>>n>>m>>w;
    vector<pair<int,int>>a(n+1);

    vector<int>p(n+1,0);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        u=find(p[u],p);
        v=find(p[v],p);
        if(v!=u)p[u]=v;
    }


    for(int i=1;i<=n;i++)
    {
        if(p[i]!=i)
        {
           int x=find(p[i],p);
           a[x].first+=a[i].first;
           a[x].second+=a[i].second;
           a[i].first=0;
           a[i].second=0;

        }
    }

    int dp[w+1]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=w;j>=a[i].first;j--)
        {
            dp[j]=max(dp[j],dp[j-a[i].first]+a[i].second);
        }
    }
    cout<<dp[w]<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}
