//https://leetcode.cn/problems/card-flipping-game/description/
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        //水题
        //如果存在正面和背面数字都是一样的，假设这个数字为x，那么x显然是不可能成为答案的，因为怎么翻转都不行
        //若一个数y，没有存在正面front[i]=backs[i]=y的情况下，那么是一定能作为答案的
        //证明过程略
        unordered_set<int>q;
        int ans=9999999;
        for(int i=0;i<fronts.size();i++)if(fronts[i]==backs[i])q.insert(fronts[i]);
        for(int i=0;i<fronts.size();i++)
        {
            if(q.find(fronts[i])==q.end())ans=min(ans,fronts[i]);
            if(q.find(backs[i])==q.end())ans=min(ans,backs[i]);    
            
        }
        if(ans==9999999)ans=0;
        return ans;
    }
};

