#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

void solve()
{
    ll n, m;
    cin>>n>>m;
    string s1, s2;
    cin>>s1>>s2;
    ll dp[n+1][m+1], best=0;
    memset(dp, 0, sizeof(dp));
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=m; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            
            if(dp[i][j]>best)
            {
                best = dp[i][j];
            }
        }
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
