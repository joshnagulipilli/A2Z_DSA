#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag=1;
    for(int i=2;i*i<=n;i++)       // for(int i=2;i<=sqrt(n);i++) here it always calculate sqrt(n) to check whether i<=sqrt(n) time taken is o(sqrt(n) +log(n));
    {
        if(n%i==0)
        {
            flag=0;
        }
    }
    if(!flag) cout<<"NO";
    else cout<<"YES";
}