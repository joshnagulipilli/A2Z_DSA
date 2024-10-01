#include<bits/stdc++.h>
using namespace std;

//brute using two loops 

int brute(vector<int>& arr,int N)       //o(n*n) + o(1)
{
   int n=arr.size();
   int ans=-1;
   bool flag;
   for(int i=1;i<=N;i++)
   {
     flag=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==i)
        {
            flag=1;
            break;
        }
    }
    if(flag==0) return  i;
   }
   
   return 0;
}

//better using hashing 

int better(vector<int>& arr,int N)   // o(n+n) + o(N)
{
   int freq[N+1]={0};
   for(int i=0;i<arr.size();i++)
   {
    freq[arr[i]]++;
   }
   int ans=0;
   for(int i=1;i<=N;i++)
   {
    if(freq[i]==0)
    {
        return i;
    }
   }
   return ans;
}
int optimal1(vector<int>& arr , int N)  //o(n) + o(1)
{
    int sum= N*(N+1)/2;
    int res=0;
    for(int i=0;i<arr.size();i++)
    {
        res+=arr[i];
    }
    return sum-res;
}

//using xor

int optimal2(vector<int>& arr , int N)   // o(n+n) + o(1)
{  
    int xo=0;
    int j=0;
    for(int i=1;i<=N;i++)
    {
        xo=xo^i;
        
    }for(int i=0;i<arr.size();i++)
    {
        xo=xo^arr[j++];
        
    }
    
    return xo;

}


int optimal3(vector<int>& arr , int N)   // o(n+n) + o(1)
{  
    int xo=0;
    int yo=0;
   for(int i=0;i<arr.size();i++)
    {
        yo=yo^(i+1);   // gets until 4 if n=5
        xo=xo^arr[i];
    }
    yo^=N;     // since N is not included in i yo
    return xo^yo;

}


int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<brute(arr,k)<<endl;
    cout<<better(arr,k)<<endl;
    cout<<optimal1(arr,k)<<endl;
    cout<<optimal2(arr,k)<<endl;
      cout<<optimal3(arr,k)<<endl;
}
