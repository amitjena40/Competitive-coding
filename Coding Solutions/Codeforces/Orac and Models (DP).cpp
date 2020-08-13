#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

ll dp[100001];

ll fn(ll a[], ll idx, ll n)
{
    if(idx>n)
    {
        return 0;
    }
    
    if(dp[idx]>-1)
    {
        return dp[idx];
    }
    
    ll count = 0;
    for(ll i=2*idx; i<=n; i += idx)
    {
        if(a[idx]<a[i])
        {
            count = max(count, 1 + fn(a, i, n));
        }
    }
    dp[idx] = count;
    return dp[idx];
}

void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    
    memset(dp, -1, sizeof(dp));
    ll best=0;
    for(ll i=1; i<=n; i++)
    {
        best = max(best, 1 + fn(a, i, n));
    }
    cout<<best<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
