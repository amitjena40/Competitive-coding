#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n, m, ans;
    cin>>n>>m;
    if(n==1)
    {
        ans =0;
    }
    else
    {
        if(n==2)
        {
            ans = m;
        }
        else
        {
            ans = 2*m;
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
