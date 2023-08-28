//https://www.acwing.com/problem/content/description/3406/
//应该是速度最快的，对比他们枚举两次的方法
//主要思路是用cnt记录状态
//从上一个点到这一个点的不同阵营个数大于1 说明一定不合法,那么直接舍弃即可
//当阵营不同，但是连接的路线小于1时，一定是当前最优解
//需要继承上一个点的状态
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int mod=998244353;
const int N=3e4+10;
int check[1000];//用于检查两个是否相等
int h[N],ne[N],e[N],w[N],idex=1;
int g[1000][1000];
void init()
{
    memset(h,-1,sizeof(h));
    memset(ne,0,sizeof(ne));
    memset(e,0,sizeof(e));
    memset(g,0,sizeof(g));
    idex=1;
    
}
void add(int a,int b,int c)
{
    e[idex]=b;
    ne[idex]=h[a];
    w[idex]=c;
    h[a]=idex++;
}
void dj()
{
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    int vis[1000]={0},dist[1000]={0},cnt[1000]={0};;
    memset(dist,0x3f3f3f3f,sizeof(dist));
    dist[1]=0;

    while(q.size())
    {
        auto [d,v]=q.top();
        q.pop();
        if(vis[v])continue;
        vis[v]=1;
        for(int i=h[v];i!=-1;i=ne[i])
        {

            int u=e[i];
            if(dist[u]>=dist[v]+w[i])
            {
                if(check[u]!=check[v]&&cnt[v]>0)continue;
                else
                {
                    if(check[u]!=check[v])cnt[u]+=1;//不同就加1
                    else cnt[u]=cnt[v];//继承之前的状态
                    dist[u]=dist[v]+w[i];
                    if(u==2)continue;
                    q.push({dist[u],u});
                }
                    
            }
        }
    }
    if(dist[2]!=0x3f3f3f3f)printf("%d\n",dist[2]);
    else printf("-1\n");
    return ;
}
void solve(int n)
{
    init();
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        add(a,b,t);
        add(b,a,t);
       
    }
    for(int i=1;i<=n;i++)scanf("%d",&check[i]);
    dj();
    return;

}
int main()
{
    
    int n=-1;
    while(n!=0)
    {
        scanf("%d",&n);
        if(n==0)break;
        solve(n);
    }
    return 0;
}
