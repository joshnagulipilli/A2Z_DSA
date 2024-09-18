#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
	{  
        int p=i;
        for(int j=1;j<=(2*n);j++)
        {
            if(j<=i) cout<<j;
            else if(j>=(2*n-i) && p!=0) 
            {
                cout<<p;
                p--;
            }
            else{
                cout<<" ";
            }
        }
		cout<<endl;
	}
}

//wrong ans