/*
 *差分，用map映射下标
 */
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        //[nums[i]-k,nums[i]+k]
        vector<int>temp;
        int n=nums.size();
        map<int,int>b;
        b[-200001]=0;
        b[200001]=0;
        for(int i=0;i<n;i++)
        {
            int l=nums[i]-k;
            int r=nums[i]+k;
            b[l]+=1;
            b[r+1]-=1;
            
        }
        int ans=0;
        int last=-200001;
        for(auto i:b)
        {
            if(i.first==-200001||i.first==200001)continue;
            if(last==-2001001)
            {
                last=i.first;
                continue;
            }
            b[i.first]+=b[last];
            last=i.first;
        }
        for(auto i:b)ans=max(ans,i.second);
        return ans;
    }
};

