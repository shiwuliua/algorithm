//https://leetcode.cn/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2023-09-07
//二分
//二分总花费时间即可
//7/9/2023
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        
        sort(ranks.begin(),ranks.end());
      
        long long l=1,r=1000000000000000;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(check(mid,ranks,cars))r=mid;
            else l=mid+1;
        }
        return l;
    }
    bool check(long long x,vector<int>&ranks,int cars)
    {
        long long counts=0;
        for(int i=0;i<ranks.size();i++)counts+=(long long)sqrt(x/ranks[i]);
        return counts>=cars;
    }
};
