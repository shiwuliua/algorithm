//https://www.cnblogs.com/wuliua/articles/17565256.html 题解
#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int h[N],ne[N],e[N],w[N],idex;
void add(int a,int b)
{
    e[idex]=b;
    ne[idex]=h[a];
    h[a]=idex++;
}
int find(int x,vector<int>&p)
{
    if(p[x]!=x)p[x]=find(p[x],p);
    return p[x];
}
void solve()
{
    int n,m,k;
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    vector<pair<int,int>>num(N+1);
    vector<int>temp(k+2,0),vis(N+1,0),p(N+1,0);
    for(int i=0;i<=n;i++)p[i]=i;

    for(int i=1;i<=m;i++)
    {
        cin>>num[i].first>>num[i].second;
        add(num[i].first,num[i].second);
        add(num[i].second,num[i].first);
    }
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>temp[i];
        vis[temp[i]]=1;
    }
    int total=n-k;
    for(auto [x,y]:num)
    {
        int v=find(p[x],p);
        int u=find(p[y],p);
        if(vis[x]!=1&&vis[y]!=1)
        {
            if(v!=u)
            {
                p[v]=u;
                total--;
            }
        }

    }

    vector<int>ans(N+2,0);
    ans[k+1]=total;
    //不连接被炸毁情况下的点个数
    for(int j=k;j>=1;j--)
    {
        int v=temp[j];
        total++;//算上当前的点

        for(int i=h[v];i!=-1;i=ne[i])
        {
            int u=e[i];

            if(vis[u])continue;
            int x=find(p[v],p);
            int y=find(p[u],p);
            if(x!=y)
            {
                p[x]=y;
                total--;
            }
        }
        ans[j]=total;
        vis[v]=0;
    }

    for(int i=1;i<=k+1;i++)cout<<ans[i]<<endl;
    return;




}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}
