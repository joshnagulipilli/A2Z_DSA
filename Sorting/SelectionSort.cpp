#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[min_index]>v[j])
            {
                min_index=j;
            }
        }
        if(min_index!=i) swap(v[min_index],v[i]);
    }
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    return 0;
}