//拓扑排序
//https://leetcode.cn/problems/course-schedule-ii/?envType=daily-question&envId=2023-09-10
//9月10号
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
      
        int n=prerequisites.size();
        vector<int>g[n+10];
        vector<int>cnt(n+10,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            g[b].push_back(a);
            cnt[a]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(cnt[i]==0)
            {
                
                q.push(i);
                ans.push_back(i);
            }
        }
        while(q.size())
        {
            auto v=q.front();
            q.pop();
            for(int i=0;i<g[v].size();i++)
            {
                int u=g[v][i];
                cnt[u]--;
                if(cnt[u]==0)
                {
                    q.push(u);
                    ans.push_back(u);
                }
            }
        }
        
        if(ans.size()!=numCourses)
        {
            ans.clear();
            return ans;
        }else
        {
           
            return ans;
        }
        
    }
};
