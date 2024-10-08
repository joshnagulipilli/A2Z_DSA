
#include<bits/stdc++.h>
using namespace std;

//sum is always 0
vector<vector<int>> brute(vector<int>& arr,int sum)   //   o(n*n*n*n) + o(2*no.of quads)
{  
    set<vector<int>>st;
    int n=arr.size();
    if(n==3) return {};
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    long long s=arr[i]+arr[j];
                    s+=arr[k];
                    s+=arr[l];
                    if(s==sum)
                    {
                        vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> better(vector<int>& arr,int sum)  // o(n*n*n*logm) + o(2* no of quads + (n) - for hashset) 
{
   int n=arr.size();
   set<vector<int>>st;      //space o(no of quads)
   for(int i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        set<int>hash;         //space o(n) - stores j-k range elements 
        for(int k=j+1;k<n;k++)
        {
            int fourth=-(arr[i]+arr[k]+arr[j]);
            if(hash.find(fourth)!=hash.end())
            {
                vector<int>temp={arr[i],arr[j],arr[k],fourth};  // constant space
                sort(temp.begin(),temp.end());                        //constant time for quads
                st.insert(temp);                                 //o(log n)
            }
            hash.insert(arr[k]);                                //o(log n)
        }
    }
   }
   vector<vector<int>>ans(st.begin(),st.end());            //space o(no of quads)
   return ans;
}


vector<vector<int>> optimal(vector<int>& arr,int sum)    // o(nlogn * n*n*n)  + o(no of quads)
{
        vector<vector<int>>ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && arr[j]==arr[j-1]) continue;// since i+1 is the first element of j we have to compare from 2nd element

                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    long long  res=arr[i]+arr[j];
                    res+=arr[k];
                    res+=arr[l];
                    if(res==sum)
                    {
                        vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && arr[k]==arr[k-1]) k++;
                        while(k<l && arr[l]==arr[l+1]) l--;
                    }
                     else if(res<0)
                    {
                        k++;
                    }
                    else 
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        
        cin>>arr[i];
    }
    // vector<vector<int>>ans= brute(arr,sum);
    // vector<vector<int>>ans= better(arr,sum);
    vector<vector<int>>ans= optimal(arr,sum);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}