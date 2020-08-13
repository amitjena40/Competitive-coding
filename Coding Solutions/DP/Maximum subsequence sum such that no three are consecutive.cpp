#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[101];

void solve()
{
    ll n;
    cin>>n;
    
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    memset(dp, 0, sizeof(dp));
    
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    
    for(ll i=2; i<n; i++)
    {
        ll option1 = dp[i-1];
        ll option2 = dp[i-2] + a[i];
        ll option3 = dp[i-3] + a[i-1] + a[i];
        dp[i] = max(option1, max(option2, option3));
    }
    
    cout<<dp[n-1]<<"\n";
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
