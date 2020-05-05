#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[51][51];

void solve()
{
    ll n, m;
    cin>>n>>m;
    ll c[n+1][m+1];
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            cin>>c[i][j];
        }
    }
    
    memset(dp, 0, sizeof(dp));
    ll max = INT_MIN;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            if(c[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            }
            
            if(max<dp[i][j])
            {
                max = dp[i][j];
            }
        }
    }
    
    cout<<max<<"\n";
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
