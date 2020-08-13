#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[1001];

void solve()
{
    ll h;
    cin>>h;
    cout<<dp[h]<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(ll i=2; i<=1000; i++)
    {
        dp[i] = ((dp[i-1]%mod)*(((2*dp[i-2])%mod+dp[i-1]%mod)%mod)%mod);
    }
    while(t--)
    {
        solve();
    }
    return 0;
}
