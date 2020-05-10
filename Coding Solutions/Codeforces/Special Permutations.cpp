#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n;
    cin>>n;
    if(n<4)
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        ll a;
        if(n%2!=0)
        {
            a = n;
        }
        else
        {
            a = n-1;
        }
        for(ll i=a; i>=1; i-=2)
        {
            cout<<i<<" ";
        }
        cout<<"4 2 ";
        for(ll i=6; i<=n; i+=2)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
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
