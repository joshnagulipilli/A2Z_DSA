#include<bits/stdc++.h>
using namespace std;


int brute(vector<int>& arr,int k)  //o(n*n*n) + o(1)
{
    int max_len=0;
     for(int i=0;i<arr.size();i++)
     {
        for(int j=i;j<arr.size();j++)
        {
            int sum=0;
             for(int p=i;p<=j;p++)
             {
                sum+=arr[p];
             }
             if(sum==k)
             {
                max_len=max(max_len,j-i+1);
             }
        }
     }
     return max_len;
}

int brute2(vector<int>& arr,int k)  //o(n*n) + o(1)
{
    int max_len=0;
     for(int i=0;i<arr.size();i++)
     {
        int sum=0;
        for(int j=i;j<arr.size();j++)
        {
                sum+=arr[j];
             if(sum==k)
             {
                max_len=max(max_len,j-i+1);
             }
        }
     }
     return max_len;
   
}

//using hashing  works for both negatives and positives 

int better(vector<int>& arr,int k)    // o(nlogn) + o(n);
{
  map<int,int>pref;
  int sum=0;
  int max_len=0;
  int i=0;
  while(i<arr.size())
  {
    sum+=arr[i];
    if(sum==k)
    {
        max_len=max(max_len,i+1);
    }
    int rem=sum-k;
    if(pref.find(rem)!=pref.end())
    {
        max_len=max(max_len,i-pref[rem]);
    }
    if(pref.find(sum)==pref.end()){           // 2 0 0 0 3 -> should return 4 , since sum 2 + 0 + 0 + 0 = 2 stores in map with index 3 gives wrong answer . so if we have zeroes and already sum exists then no need to push in map
        pref[sum]=i;
    }
    i++;
  }
  return max_len;

}


int optimal(vector<int>& arr,int k)   // o(n + n)
{
   int len=0;
   int left=0,right=0;
   int n=arr.size();
   int sum=0;
   while(right<n)                // o(n)
   {
    while(left<=right && sum>k)  // sometimes 
    {
        sum-=arr[left];
        left++;
    }
    sum+=arr[right];
    if(sum==k)
    {
        len=max(len,right-left+1);
    }
    
    right++;
   }
   return len;
}



int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
   
    cout<<brute(arr,k)<<endl;
     cout<<brute2(arr,k)<<endl;
    cout<<better(arr,k)<<endl;
    cout<<optimal(arr,k)<<endl;
}
