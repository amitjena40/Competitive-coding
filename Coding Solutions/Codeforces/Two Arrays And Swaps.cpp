#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n, k, ans;
    cin>>n>>k;
    ll a[n], b[n], suma = 0, sumb = 0;
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        suma += a[i];
    }
    
    for(ll i=0; i<n; i++)
    {
        cin>>b[i];
        sumb += b[i];
    }
    
    sort(a, a+n); sort(b, b+n);
    
    if(a[0]>=b[n-1] || k==0)
    {
        ans = suma;
    }
    else
    {
        ll ptrb = n-1, ptra = 0;
        while(k!=0 && ptrb!=-1)
        {
            if(a[ptra]<b[ptrb])
            {
                suma = suma - a[ptra] + b[ptrb];
                k--;
                ptra++;
            }
            ptrb--;
            
        }
        ans = suma;
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
