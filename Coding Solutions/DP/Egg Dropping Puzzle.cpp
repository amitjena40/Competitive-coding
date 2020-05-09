#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

ll dp[11][51];

void solve()
{
    ll n, k;
    cin>>n>>k;
    
    for(ll i=1; i<=n; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    
    for(ll j=1; j<=k; j++)
    {
        dp[1][j] = j;
    }
    
    for(ll i=2; i<=n; i++)
    {
        for(ll j=2; j<=k; j++)
        {
            dp[i][j] = INT_MAX;
            for(ll x=1; x<=j; x++)
            {
                ll res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                if(res<dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }
    
    cout<<dp[n][k]<<"\n";
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
