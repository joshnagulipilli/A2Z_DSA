#include<bits/stdc++.h>
using namespace std;


// int range inside main 10^6  outside main 10^7
//bool range inside main 10^7 outside main 10^8


//o(n log(log n)) 
int n = 1000000;
bool sieve[1000001];

void createSieve()
{
    for(int i=0;i<=n;i++) // o(n)
    {
         sieve[i]=true;
    }

    for(int i=2;i*i<=n;i++)    // log 
    {
        if(sieve[i]==true)  // only consider when it is not multiple of any previous numbers
        {
            for(int j=i*i;j<=n;j+=i)    // log    ==> both loops  log(logvn)
            {
                sieve[j]=false;
            }
        }
    }

} 

// o(n log(log n))

int main()
{
    createSieve();
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        if(sieve[N]==true)
        {
            cout<<"YES";

        }
        else {
            cout<<"NO";
        }
    }
}