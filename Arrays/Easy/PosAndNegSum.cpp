#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<better(arr,k)<<endl;

}