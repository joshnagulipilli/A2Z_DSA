
#include<bits/stdc++.h>
using namespace std;

void brute(vector<int>& arr)   //o(n*n) + o(1)
{  
   int n=arr.size();
   int miss=-1,reap=-1;
   for(int i=1;i<=n;i++)
   {
    int cnt=0;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==i) cnt++;
    }
    if(cnt==0) miss=i;
    if(cnt==2) reap=i;
    if(reap!=-1 && miss!=-1) break;
   }
   cout<<reap<<" "<<miss<<"\n";
}
//using hashing
void better(vector<int>& arr)  //o(2n) + o(n) 
{
   int n=arr.size();
   unordered_map<int,int> mp;
   int reap=-1,miss=-1;
   for(auto it:arr)
   {
    mp[it]++;
   }
   for(int i=1;i<=n;i++)
   {
    if(mp.find(i)==mp.end()) miss=i;
    else if(mp[i]==2) reap=i;
   }
   cout<<reap<<" "<<miss<<endl;
}
//using maths formulae
// x->repeating , y->missing
// x-y = sum of array - sum till n
//x^2 - y^2 = sum of squares of array - sum of squares till 1 to n
//(x+y)(x-y) = ans
//evaluate x-y in this 
void optimal(vector<int>& arr)  //o(n)
{
   long long n=arr.size();
   long long sn=(n*(n+1))/2;
   long long s2n = (n*(n+1)*((2*n)+1))/6;
   long long s=0,s2=0;
   for(auto it:arr) 
   {
        s+=it;
        s2+=(long long)it*(long long)it;
   }
     //S-Sn = X-Y:
   long long val1 = s-sn;
   // S2-S2n = X^2-Y^2
   long long val2 = s2-s2n;
   
    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2=val2/val1;
    // x+y=val1
    // x-y=val2
    //----------
    //2x = val1+val2   -> x=(val1+val2)/2
    long long x = (val1+val2)/2;
    long long y = x-val1;
    cout<<(int)x<<" "<<(int)y<<endl;
}

//very logical
//x^y = ans ; 

void optimal2(vector<int>& arr)  
{
    int n=arr.size();
    int x=0;
    for(int i=0;i<n;i++)
    {
        x=x^arr[i];
        x=x^(i+1);
    }
    //finding where do the bits of x and y differ - 1
    int bit=0;
    while(1)
    {
        if(x & (1<<bit)==1)
          break;
        bit++;
    }

    //now seggregate all the zero bit occurs at particular bit no and one bit
    int zero=0;
    int one=0;
    //for array elements
    for(int i=0;i<n;i++)
    {
        //part of 1 group
        if(arr[i] & (1<<bit)!=0)
        {
            one = one ^ arr[i];
        }
        else{
            zero=zero ^ arr[i];
        }
    }
    //for 1 to n 
    for(int i=1;i<=n;i++)
    {
        //part of 1 group
        if(i & (1<<bit)!=0)
        {
            one = one ^ i;
        }
        else{
            zero=zero ^ i;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==zero) cnt++;
    }
    if(cnt==2) 
    {
        cout<<zero<<" "<<one<<endl;
    }
    else cout<<one<<" "<<zero<<endl;
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
    brute(arr);
    better(arr);
    optimal(arr);
    optimal2(arr);
    return 0;
}