//自己写的复杂版本，其实完全搞复杂了
//为用一个大根堆处理出了在当前每个nums[i]出现出现次数最多的📔
//再跟最后一个数字作对比

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      
        priority_queue<pair<int,int>>q;
        map<int,int>count;
        int n=nums.size();
        vector<pair<int,int>>sums;
        sums.push_back({0,0});
        for(int i=0;i<n;i++)
        {
            count[nums[i]]+=1;
            q.push({count[nums[i]],nums[i]});
            auto t=q.top();
            sums.push_back({t.first,t.second});
        }
        int ans=-1;

        for(int i=1;i<=n-1;i++)
        {
            int x=sums[i].first;
            int y=sums[i].second;
            int x2=sums[n].first;
            int y2=sums[n].second;
            if(y2!=y)continue;
            int len=x2-x;
            if(x>i/2&&(len)>(n-i)/2)
            {
                ans=i-1;
                break;
            }
          
        }
        return ans;

    }
};
//简易版本下用两个哈希表就可以搞定了

