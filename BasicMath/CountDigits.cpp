#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n>0)
    {
        cnt++;
        n/=10;
    }
    cout<<cnt;
    return 0;  


    // int cnt=(int)(log10(n)+1);
}