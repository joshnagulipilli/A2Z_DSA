// To calculate the sum of divisors for each integer k (where  1 <= k <=N ), a number  d  is a divisor of k  if k % d = 0 . The sum of divisors function for an integer k  is the sum of all divisors of k .

//  Optimized Approach:
// Rather than calculating divisors for each  k individually, you can reverse the problem: each number d  divides some numbers from 1 to N , specifically, numbers that are multiples of  d . For example, 2 divides 2, 4, 6, 8, etc. So, for each d, you can calculate how many times it will contribute to the sum (i.e., how many multiples of d  there are up to  N .


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
//     for(int i=1;i<=n;i++) // give tle
//     {
//         int res=0;
//         for(int j=1;j<=i;j++)
//         {
//             res+=((i%j==0)?j:0);
//         }
//         sum+=res;

//     }
//    cout<<sum;


  // so in o(n^2) , 2 divides 2,4,6,8 it itervatively j checks for every i th time . 
  // so in o(n), we can take from i - 2->8 by j how many times it divides and sum up;
  for(int i=1;i<=n;i++)
  {
    sum+=i*(n/i);
  }
  cout<<sum;

}