#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

void solve()
{
    ll n, ins, del, copy;
    cin>>n>>ins>>del>>copy;
    ll dp[n+1];
    dp[0] = 0;
    dp[1] = ins;
    for(ll i=2; i<=n; i++)
    {
        if(i%2==0)
        {
            dp[i] = min(dp[i-1]+ins, dp[i/2] + copy);
        }
        else
        {
            dp[i] = min(dp[i-1]+ins, min(dp[(i+1)/2]+copy+del, dp[(i-1)/2]+copy+ins));
        }
    }
    cout<<dp[n]<<"\n";
}

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
