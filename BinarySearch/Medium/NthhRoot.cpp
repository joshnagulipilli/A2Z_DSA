#include<bits/stdc++.h>
using namespace std;


//return 1 if ==m
//return 2 if >m
//return 0 if <m
int fun(int mid,int n , int m)
{
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res *= mid;
        if(res>m) return 2;
    }
    if(res==m) return 1;
    return 0;
   
}

int binary(int n, int m){     // o(log n) + o(1)
    int low = 1 ,high = m;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(fun(mid,n,m)==1){
            return mid;
        }
        else if(fun(mid,n,m)==2) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<binary(n,m)<<endl;
}