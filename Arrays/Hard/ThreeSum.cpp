
#include<bits/stdc++.h>
using namespace std;

//sum is 0 always 
vector<vector<int>> brute(vector<int>& arr,int sum)     // o(n*n*n * log(set insertion triplets insertion operstion )) +  o(2*triplets length in array)
{  
    set<vector<int>>st;              // for unique solutions
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
              for(int k=j+1;k<arr.size();k++)
              {
                if(arr[i]+arr[j]+arr[k]==sum)
                {
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());      // sorting only three elements not takes much complexity
                    st.insert(temp);
                }
              }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
vector<vector<int>> better(vector<int>& arr,int sum)  // o(n*n log(triplets))  + o(2*triplets + n(hashset)) 
{
   set<vector<int>>st;
   for(int i=0;i<arr.size();i++)
   {
     set<int> hash;
    for(int j=i+1;j<arr.size();j++)
    {
        int third=-(arr[i]+arr[j]);
        if(hash.find(third)!=hash.end())
        {
            vector<int>temp={arr[i],arr[j],third};
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        hash.insert(arr[j]);
    }
   }
   vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}


vector<vector<int>> optimal(vector<int>& arr,int sum)    //o(nlogn + n*n)  + o(no of triplets - x say)
{
           vector<vector<int>>ans;                           //space o(no .of triplets)
           sort(arr.begin(),arr.end());                      //o(nlogn)
           int n=arr.size();                                 //o(n)
           for(int i=0;i<n;i++)
           {
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k)                                    //o(n-1,n-2,n-3..........n-n)
            {
                int res=arr[i]+arr[k]+arr[j];
                if(res==sum)
                {
                    ans.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1]) j++;               // o(min time )
                    while(j<k && arr[k]==arr[k+1]) k--;
                }
                else if(sum>0) k--;
                else j++;
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