
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>& arr)   
{

}
int better(vector<int>& arr)
{

}
void optimal(vector<int>& arr)       //o(n) + o(1)
{
    int n=arr.size();
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // cout<<brute(arr)<<endl;
    // cout<<better(arr)<<endl;
    optimal(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}