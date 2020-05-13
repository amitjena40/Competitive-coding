#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    
    ll b[n+1], c[n+1];
    b[n] = a[n];
    for(ll i=n-1; i>=1; i--)
    {
        b[i] = __gcd(a[i], b[i+1]);
    }
    
    for(ll i=1; i<=n-1; i++)
    {
        c[i] = (a[i]*b[i+1])/__gcd(a[i], b[i+1]);
    }
    
    ll ans = c[1];
    for(ll i=2; i<=n-1; i++)
    {
        ans = __gcd(ans, c[i]);
    }
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }*/
    solve();
    return 0;
}
