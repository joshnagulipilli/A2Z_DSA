//it should not reach out of bounds of integer values [-2^31 , 2^31-1]
// 2^31 = 2147483648

#define bound 2147483648
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    long long temp=x;
    long long res=0;
    temp=abs(x);
    while(temp>0)
    {
        res=res*10+(temp%10);
        temp/=10;
    }
    if(res>bound-1 || res<((-1)*(bound))) cout<<0;
    if(x<0) cout<<(-1)*res;
    cout<<res;
    return 0;
}
