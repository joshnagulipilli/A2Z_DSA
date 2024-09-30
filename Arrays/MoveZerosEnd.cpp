
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr)         //o(n+(n-x)+o(n))   + o(n)
{
   vector<int>temp;                   // space o(n)
   for(int i=0;i<arr.size();i++)     // o(n)
   {
    if(arr[i]!=0)
    {
        temp.push_back(arr[i]);
    }
   }
   for(int i=temp.size();i<arr.size();i++)   //o(n-x)
   {
    temp.push_back(0);
   }
   for(int i=0;i<arr.size();i++)   //o(n)
   {
    arr[i]=temp[i];
   }
}
int better(vector<int>& arr)
{

}
void optimal(vector<int>& arr)      // o(x+n-x) => o(n)  + o(1)
{
    //using two pointers
    int j=-1;
    int n=arr.size();
    for(int i=0;i<n;i++)   //o(x)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1) return ;
    for(int i=j+1;i<n;i++)   //o(n-x)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }

    
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
    //  brute(arr);
    //  better(arr);
    optimal(arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}