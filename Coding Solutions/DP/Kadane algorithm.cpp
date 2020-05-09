#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back()

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
    
    ll best_sum=INT_MIN, curr_sum=0;
    {
        for(auto x:a)
        {
            curr_sum += x;
            if(curr_sum>best_sum)
            {
                best_sum = curr_sum;
            }
            
            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }
    }
    cout<<best_sum<<"\n";
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
