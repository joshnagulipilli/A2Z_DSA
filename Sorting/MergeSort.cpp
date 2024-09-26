#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int low,int mid,int high)
{
     vector<int>temp;
     int left=low;
     int right=mid+1;
     while(left<=mid && right<=high)
     {
        if(v[left]<=v[right]) temp.push_back(v[left++]);
        else temp.push_back(v[right++]);
     }
     while(left<=mid)
     {
         temp.push_back(v[left]);
         left++;
     }
       while(right<=high)
     {
         temp.push_back(v[right]);
         right++;
     }
     for(int i=low;i<=high;i++)
     {
        v[i]=temp[i-low];
     }

}

void MergeSort(vector<int>& v,int l,int h)
{
       if(l>=h) return ;
       int mid=(l+h)/2;
       MergeSort(v,l,mid);
       MergeSort(v,mid+1,h);
       merge(v,l,mid,h);
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
    MergeSort(v,0,n-1);
    for(int i=0;i<n;i++)
    { 
        cout<<v[i]<<" ";
    }
    return 0;
}