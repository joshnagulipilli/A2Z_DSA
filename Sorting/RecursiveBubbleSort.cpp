#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>& v,int n)
{
    if(n==1) return ;
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        if(v[i]>v[i+1])
        {
            swap(v[i],v[i+1]);
            flag=1;
        }
    }
    if(flag==0) return ;

    fun(v,n-1);
}


int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    fun(v,n);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    
}