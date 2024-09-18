#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0,temp=n,x=n;
    while(temp>0)
    {
        ans++;
        temp/=10;
    }
    int res=0;
    while(x>0)
    {
        int r=x%10;
        res=res+(pow(r,ans));
        x/=10;
    }
    if(res==n) cout<<"True";
    else cout<<"False";
}