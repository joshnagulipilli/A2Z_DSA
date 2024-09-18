#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1) 
    {
        cout<<"*";
    }
    for(int i=0;i<n;i++)
    {
        cout<<"*";
    }
    cout<<endl;
    for(int i=1;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0 || j==n-1) 
              cout<<"*";
            else 
                cout<<" ";
        }
        
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"*";
    }
}

