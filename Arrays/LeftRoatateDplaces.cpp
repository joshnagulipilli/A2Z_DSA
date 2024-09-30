
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr,int d)   
{
  int n=arr.size();
  vector<int>temp(n);
  d=d%arr.size();
  for(int i=0;i<d;i++)
  {
     temp[i+d-1]=arr[i];
  }
  for(int i=d;i<n;i++)
  {
    temp[i-d]=arr[i];
  }
  for(int i=0;i<n;i++)
  {
    arr[i]=temp[i];
  }
}
void better(vector<int>& arr,int d)
{

}
void optimal(vector<int>& arr,int d)       
{
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
    
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
    int d;
    cin>>d;
    //  brute(arr,d);
    //  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    //  better(arr,d);
    // for(int i=0;i<n;i++)  cout<<arr[i]<<" ";
    optimal(arr,d);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}