//水题
//https://www.acwing.com/problem/content/5142/

#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;
vector<int>g[500];
int ans=0;
string turn(string s)
{
    for(int i=0;i<s.size();i++)if(s[i]<='Z'&&s[i]>='A')s[i]=s[i]-'A'+'a';
    return s;
}
void dfs(int u,int cnt)
{
    ans=max(ans,cnt);
    for(int i=0;i<g[u].size();i++)dfs(g[u][i],cnt+1);
    
}
int main()
{
    int n;cin>>n;
    map<string,int>q;
    q["bessie"]=1;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;cin>>s1>>s2;
        s1=turn(s1);s2=turn(s2);
        if(q[s1]==0)q[s1]=++cnt;
        g[q[s2]].push_back(q[s1]);
    }
    dfs(1,1);
    cout<<ans<<endl;
    return 0;
}
