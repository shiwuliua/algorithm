//拿数字模拟了下 猜的规律
//https://www.acwing.com/problem/content/description/5144/
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,t;
    cin>>a>>b;
    ll ans=a/b;
    t=a%b;
    
    while(t!=0)
    {
        a=b;
        b=t;
        ans+=a/b;
        t=a%b;
    }
    cout<<ans<<endl;
   
}
