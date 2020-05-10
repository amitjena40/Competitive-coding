#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n, k;
    cin>>n>>k;
    ll a = n-(k-1);
    ll b = n-2*(k-1);
    if(a>0 && a%2!=0)
    {
        cout<<"YES\n";
        for(ll i=0; i<k-1; i++)
        {
            cout<<"1 ";
        }
        cout<<a<<"\n";
    }
    else if(b>0 && b%2==0)
    {
        cout<<"YES\n";
        for(ll i=0; i<k-1; i++)
        {
            cout<<"2 ";
        }
        cout<<b<<"\n";
    }
    else
    {
        cout<<"NO\n";
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
