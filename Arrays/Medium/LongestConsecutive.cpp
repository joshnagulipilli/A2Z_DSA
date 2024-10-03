
#include<bits/stdc++.h>
using namespace std;

bool fun(int n,vector<int>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==n) return true;
    }
    return false;
}

int brute(vector<int>& arr)      //o(n*n) + o(1)
{ 
    int n=arr.size();
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int len=1 ;
        while(fun(x+1,arr)==true)
        {
            x++;
            len++;
        }
        maxi=max(len,maxi);
        }
        // cout<<len<<endl;
    return maxi;
}


int better(vector<int>& arr)   //o(n) + o(1)
  {
   int n=arr.size();
   sort(arr.begin(),arr.end());
   int maxi=1;
   int len=0;
   int last=INT_MIN;
   for(int i=0;i<n;i++)
   {
    if(arr[i]-1==last)
    {
       len++;
       last=arr[i];
    }
    else if(arr[i]!=last) 
    {
        len=1;
        last=arr[i];
    }
    maxi=max(maxi,len);
   }
   return maxi;
}

//using unordered_set which take all operations of complexity o(1) unlike set o(log n)

int optimal(vector<int>& arr)    //  o(n+n+2n) = o(n)    + o(n)
{

    //base case is always imp
    if(arr.size()==0) return 0;
    unordered_set<int>st;           //o(n) space 
    for(int i=0;i<arr.size();i++)      //o(n)
    {
        st.insert(arr[i]);
    }
    int maxi=1;
    for(auto it:st)    //o(n)
    {
        //if current element is not first then it checks for previous
        if(st.find(it-1)==st.end())
        {
            int cnt=1;
            int x=it;
            //checks for all consecutive  elements in set until it gets last
            while(st.find(it+1)!=st.end())                                               // not all elements enter into if  so , it takes 2N complexity
            {
                cnt+=1;
                x+=1;
            }
            maxi=max(maxi,cnt);
        }
    }
    return maxi;
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
    // cout<< better(arr)<<endl;
    cout<<optimal(arr)<<endl;

    cout<<endl;

}