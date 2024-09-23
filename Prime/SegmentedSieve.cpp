#include<bits/stdc++.h>
using namespace std;

int N=1000000;
vector<int>sieve(N+1);
void createSieve()
{
    for(int i=2;i<=N;i++)
    {
        sieve[i]=true;
    }
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]==true)
        {
            for(int j=i*i;j<=N;j+=i)
            {
                sieve[j]=false;
            }
        }
    }
}

vector<int> generate(int n)
{
    vector<int>ds;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i]==true)
        {
            ds.push_back(i);
        }
    }
    return ds;
}

int main()
{
    createSieve();
    int l=110,r=130;
    vector<int>primes = generate(sqrt(r));
    // now creating dummy array of size(r-l+1) and make everyone as 1
    int dummy[r-l+1];
    for(int i=0;i<r-l+1;i++)
    {
        dummy[i]=1;
    }

    //step 3 : mark all multiples of primes in (l-r) range through the generated primes
    for(auto pr:primes)
    {
        int firstMultiple=(l/pr)*pr;
        if(firstMultiple<l)
        {
            firstMultiple+=pr;
        }
        for(int j=max(pr*pr,firstMultiple);j<=r;j+=pr)
        {
            dummy[j-l]=0;
        }
    }
    for(int i=l;i<=r;i++)
    {
        if(dummy[i-l]==1) cout<<i<<" ";
    }
}
