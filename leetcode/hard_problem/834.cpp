//dp
//https://leetcode.cn/problems/sum-of-distances-in-tree/description/
class Solution {
public:
    
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
                
    vector<int>ans(n),cnt(n);
    vector<vector<int>>g(n);
    for(auto &e:edges)
    {
        int x=e[0];
        int y=e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    function<void(int,int,int)> dfs = [&](int v,int f,int d)
    {
        
        cnt[v]=1;
        ans[0]+=d;
        for(int i=0;i<g[v].size();i++)
        {
            int u=g[v][i];
            if(u==f)continue;
            dfs(u,v,d+1);
            cnt[v]+=cnt[u];
        }
        
       
    };
    //设一个节点为u  他的父节点为v，那么显然u到全部节点的距离等于distance[v]+(n-cnt[v])-cnt[u];
    //distance[v]代表v节点到其他所有子节点的距离，cnt[]代表节点数
    function<void(int,int,int)> dfs2 = [&](int v,int f,int d)
    {
        
        ans[v]=d;
        for(int i=0;i<g[v].size();i++)
        {
            int u=g[v][i];
            if(u==f)continue;
            dfs2(u,v,d-cnt[u]+n-cnt[u]);
            
        }
        
       
    };
     

    dfs(0,-1,0);
    dfs2(0,-1,ans[0]);
    return ans;
    }
    
};
