#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool p=1;
    for(int i=0;i<n;i++)
	{
        if(i%2==0) p=1;
        else p=0;
		for(int j=0;j<=i;j++)
		{
			cout<<p;
            p=p^1;
		}
		cout<<endl;
	}
}