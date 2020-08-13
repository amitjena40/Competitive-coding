#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n, ans=8;
    cin>>n;
    if(n==1)
    {
        ans = 0;
    }
    else if(n==3)
    {
        ans = 8;
    }
    else
    {
        for(ll i=5; i<=n; i+=2)
        {
            ans += (i-1)*(i-1)*2;
        }
    }
    cout<<ans<<"\n";
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
