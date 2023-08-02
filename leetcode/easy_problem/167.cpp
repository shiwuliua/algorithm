//https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        //简单二分
        for(int i=0;i<numbers.size();i++)
        {
            int cnt=target-numbers[i];
        
            int l=1,r=numbers.size()-1;
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if(numbers[mid]>cnt)r=mid-1;
                else l=mid;
            }
       
            if(l!=i&&l>=1&&l<=numbers.size()-1&&numbers[l]==cnt)
            {
                ans.push_back(i+1);
                ans.push_back(l+1);
                break;
            }
        }
       // sort(ans.begin(),ans.end());
        return ans;
    }
};
