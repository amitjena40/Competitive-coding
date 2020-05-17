#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    ll dp[n][2];
    for(ll i=0; i<n; i++)
    {
        dp[i][0] = dp[i][1] = 1;
    }
    
    ll res = 0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<i; j++)
        {
            if(a[j]<a[i])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            else if(a[j]>a[i])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        
        ll ans = max(dp[i][0], dp[i][1]);
        if(res<ans)
        {
            res = ans;
        }
    }
    cout<<res<<"\n";
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
