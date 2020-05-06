#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[101];

void solve()
{
    ll n, k;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    cin>>k;
    memset(dp, 0, sizeof(dp));
    
    sort(a, a+n);
    
    dp[0] = 0;
    for(ll i=1; i<n; i++)
    {
        dp[i] = dp[i-1];
        if(abs(a[i]-a[i-1])<k)
        {
            if(i>=2)
            {
                dp[i] = max(dp[i], dp[i-2] + a[i] + a[i-1]);
            }
            else
            {
                dp[i] = max(dp[i], a[i]+a[i-1]);
            }
        }
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
