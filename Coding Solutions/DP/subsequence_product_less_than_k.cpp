#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[101][101];

void solve()
{
    ll n, k;
    cin>>n>>k;
    
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    memset(dp, 0, sizeof(dp));
    
    for(ll i=1; i<=k; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            dp[i][j] = dp[i][j-1];
            
            if(a[j-1]<=i && a[j-1]>-1)
            {
                dp[i][j] += dp[i/a[j-1]][j-1] + 1;
            }
        }
    }
    
    cout<<dp[k][n];
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
