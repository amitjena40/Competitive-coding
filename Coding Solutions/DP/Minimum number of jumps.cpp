#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;
ll dp[10000001];

void solve()
{
    ll n; cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        dp[i] = INT_MAX;
    }
    
    if(a[0] == 0)
    {
        cout<<-1<<"\n";
        return;
    }
    
    dp[0] = 0;
    for(ll i=1; i<n; i++)
    {
        if(a[i] == 0 && i!=n-1)
        {
            continue;
        }
        else
        {
            for(ll j=i-1; j>=0; j--)
            {
                if(a[j] >= i-j)
                {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
    }
    
    if(dp[n-1]==INT_MAX)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<dp[n-1]<<"\n";
    }
    
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
