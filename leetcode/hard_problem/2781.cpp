class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        
        set<string>q;
        set<int>finds;
        for(auto i:forbidden)q.insert(i);
        word=" "+word;
        int ans=0;
        int l=1;
        //双指针
        //r指针往右边移动，然后依此检查[i,i+r]内的字符是否在哈希表内，i>r-10 因为字符串最长不超过10
        //假设s[i]到s[r]这里的字符串已经在哈希表里出现了，那也就说明s[i]到s[r+1,r+2,r.....n]的所有字符串都不合法
        //那就没有必要再往后看了
        //此时将左指针移动到i+1,开始检查下一个区间
        
        for(int r=1;r<word.size();r++)
        {
            for(int i=r;i>=l&&i>r-10;i--)
            {
                if(q.count(word.substr(i,r-i+1))){
                   
                    l=i+1;
                    break;
                }
            }
           
            ans=max(ans,r-l+1);

        }
       return ans;
    }
};
