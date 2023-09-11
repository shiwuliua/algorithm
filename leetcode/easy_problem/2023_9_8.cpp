//https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/description/?envType=daily-question&envId=2023-09-03
//水题
//只要把怪物到达城市的时间排个序，然后用一个time记录分钟，每一分钟吃一个怪兽，当怪物到底城市的时间<=time时，说明已经没法在该时间内消灭到底城市的所有怪物
//8/9/2023
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    
        int k=9999999;
        vector<int>sums;
        for(int i=0;i<dist.size();i++)
        {
            int t1=dist[i];
            int t2=speed[i];
            if(t1%t2!=0)sums.push_back(t1/t2+1);
            else sums.push_back(t1/t2);
            
        }
        sort(sums.begin(),sums.end());
        int cnts=0;
        int time=0;
        for(auto i:sums)
        {
            
            if(time<i)cnts+=1;
            else break;
            time+=1;

        }
    return cnts;
    }
};
