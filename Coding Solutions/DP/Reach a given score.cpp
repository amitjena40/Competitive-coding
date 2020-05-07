#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[1001][4];

ll score(ll n, ll d[], ll numD)
{
    if(n==0)
    {
        return 1;
    }
    else if(n<0)
    {
        return 0;
    }
    else if(numD==0)
    {
        return 0;
    }
    else if(dp[n][numD]>-1)
    {
        return dp[n][numD];
    }
    else
    {
        ll op1 = score(n-d[0], d, numD);
        ll op2 = score(n, d+1, numD-1);
        dp[n][numD] = op1 + op2;
        return dp[n][numD];
    }
}

void solve()
{
    ll n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    ll d[3] = {3, 5, 10};
    cout<<score(n, d, 3)<<"\n";
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
