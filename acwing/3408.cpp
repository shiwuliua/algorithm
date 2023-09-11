//https://www.acwing.com/problem/content/3408/
//水题，保持手感
//九月10号
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s;
void turn(vector<pair<int,char>>q1,int k)
{
    for(int i=0;i<q1.size();i++)
    {
       int cnt=(i+k)%q1.size();
       int  flag=q1[cnt].first;
       s[flag]=q1[i].second;
    }
    //cout<<s<<endl;
}
void solve(int k1,int k2,int k3)
{
    cin>>s;
    vector<pair<int,char>>q1,q2,q3;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='i')q1.push_back({i,s[i]});
        else if(s[i]>='j'&&s[i]<='r')q2.push_back({i,s[i]});
        else q3.push_back({i,s[i]});
    }
    turn(q1,k1);turn(q2,k2);turn(q3,k3);
    cout<<s<<endl;
    
    return;
    
}
int main()
{
    int k1=-1,k2=-1,k3=-1;
    while(1)
    {
        cin>>k1>>k2>>k3;
        if(k1==0&&k2==0&&k3==0)break;
        solve(k1,k2,k3);
    }
    return 0;
}
