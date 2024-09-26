#include<bits/stdc++.h>
using namespace std;

int quick(vector<int>& v,int low ,int high)
{
    int pivot=v[low];
    int i=low,j=high;
    while(i<j)
    {
        while(i<=high && pivot > v[i])
        {
            i++;    
        }
        while(j>=low && pivot < v[j])
        {
            j--;
        }
        if(i<j) swap(v[i],v[j]);
    }
    if(j>i) swap(v[j],v[low]);
    return j;
}

void quickSort(vector<int>& v,int low,int high)
{
    if(low<high)
    {
        int partition = quick(v,low,high);
        quickSort(v,low,partition-1);
        quickSort(v,partition+1,high);
    }
}


int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    quickSort(v,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}