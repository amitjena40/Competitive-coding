#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;
ll dp[51];

void solve()
{
    ll n;
    cin>>n;
    cout<<dp[n]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    dp[0] = 0; dp[1] = 1; dp[2]=2; dp[3]=4;
    for(ll i=4; i<=50; i++)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    while(t--)
    {
        solve();
    }
    return 0;
}
