#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cnt++;
            if(n/i != i)
               cnt++;
        }
    }
    if(cnt==2) cout<<"YES";
    else cout<<"NO";


    //my way
    // int i=0;
    // if(n==1) cout<<"No";
    // else{

    // for(int i=2;i*i<=n;i++)
    // {
    //     if(n%i==0) 
    //     {
    //         cout<<"NO";
    //         break;
    //     }
    // }
    // if(i*i>n) cout<<"No"; //wrong because i*i > n always happens after loop and when loop breaks , the i is incomplete and there might be chance of getting two answers .  this condition states whether the loop has fully finished
    // else cout<<"Yes";
    // }
    return 0;
}
