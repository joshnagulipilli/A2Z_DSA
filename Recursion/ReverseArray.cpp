#include<bits/stdc++.h>
using namespace std;

void reverse(int i,vector<int>& v,int n)
{
    if(i>n/2) return ;
    swap(v[i],v[n-i-1]);
    reverse(i+1,v,n);

}

//using two variables
// void fun(int l , int r)
// {
//     if(l>=r) return ;
//     swap(v[l],v[r]);
//      fun(l+1,r-1);
// }

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    reverse(0,v,n);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}