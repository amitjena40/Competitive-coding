#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[1001][1001];

ll removal(ll a[], ll i, ll j, ll k)
{
    if(i>=j)
    {
        return 0;
    }
    else if((a[j]-a[i])<=k)
    {
        return 0;
    }
    else if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        dp[i][j] = 1 + min(removal(a, i+1, j, k), removal(a, i, j-1, k));
        return dp[i][j];
    }
}

void solve()
{
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    memset(dp, -1, sizeof(dp));
    cout<<removal(a, 0, n-1, k)<<"\n";
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
