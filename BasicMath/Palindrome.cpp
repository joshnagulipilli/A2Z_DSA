//it should not reach out of bounds of integer values [-2^31 , 2^31-1]
// 2^31 = 2147483648
//do not use long long
#define bound 2147483648

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    int temp=x;
    int res=0;
    temp=abs(x);
    while(temp>0)
    {
        if(res > (INT_MAX)/10 || res< (INT_MIN)/10) // consider 214748364
        {
            cout<<0;
            break;
        }
        res=res*10+(temp%10);
        temp/=10;
    }
    if(res>bound-1 || res<((-1)*(bound))) cout<<0;
    if(x<0) cout<<(-1)*res;
    cout<<res;
    return 0;


//  Consider x = 2147483647 (which is INT_MAX). Let’s step through the reversal process:
// Initially: ans = 0.
// Reversing 2147483647 digit by digit:
// 1st iteration: x = 2147483647, ans = 0 * 10 + 7 = 7
// 2nd iteration: x = 214748364, ans = 7 * 10 + 4 = 74
// 3rd iteration: x = 21474836, ans = 74 * 10 + 6 = 746
// 4th iteration: x = 2147483, ans = 746 * 10 + 3 = 7463
// 5th iteration: x = 214748, ans = 7463 * 10 + 8 = 74638
// 6th iteration: x = 21474, ans = 74638 * 10 + 4 = 746384
// 7th iteration: x = 2147, ans = 746384 * 10 + 7 = 7463847
// 8th iteration: x = 214, ans = 7463847 * 10 + 4 = 74638474
// 9th iteration: x = 21, ans = 74638474 * 10 + 1 = 746384741
// 10th iteration: x = 2, ans = 746384741 * 10 would result in 7463847410, which exceeds INT_MAX (2147483647).
// Why Divided by 10?
// Dividing INT_MAX (or INT_MIN) by 10 gives the threshold beyond which multiplying by 10 would definitely cause overflow.
// For example:
// INT_MAX = 2147483647, so INT_MAX / 10 = 214748364.
// If ans exceeds 214748364, multiplying it by 10 would make the result larger than 2147483647, which is the maximum value for a 32-bit integer.
// The check ensures that ans is within a safe range where multiplying it by 10 won’t cause an overflow.
}
