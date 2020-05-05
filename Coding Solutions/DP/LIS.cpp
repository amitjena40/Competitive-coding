#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[1001];

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    dp[0] = 1;
    for(ll i=1; i<n; i++)
    {
        dp[i] = 1;
        for(ll j=i-1; j>=0; j--)
        {
            if(a[i]<=a[j])
            {
                continue;
            }
            else
            {
                ll ans = dp[j]+1;
                if(ans>dp[i])
                {
                    dp[i] = ans;
                }
            }
        }
    }
    
    ll best = INT_MIN;
    for(ll i=0; i<n; i++)
    {
        if(dp[i]>best)
        {
            best = dp[i];
        }
    }
    
    cout<<best<<"\n";
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
