#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

void solve()
{
    ll n0, n1, n2;
    cin>>n0>>n1>>n2;
    
    string s1="", s2="", s3="", ans="";
    if(n1==0)
    {
        if(n0>0)
        {
            for(ll i=0; i<n0+1; i++)
            {
                s1 += '0';
            }
        }
        
        if(n2>0)
        {
            for(ll i=0; i<n2+1; i++)
            {
                s3 += '1';
            }
        }
        
        cout<<s1+s3<<"\n";
    }
    else
    {
        for(ll i=0; i<n1+1; i++)
        {
            if(i%2==0)
            {
                s2 += '1';
            }
            else
            {
                s2 += '0';
            }
        }
        
        for(ll i=0; i<n0; i++)
        {
            s1  += '0';
        }
        
        ans = s2[0] + s1 + s2.substr(1, s2.size()-1);
        
        for(ll i=0; i<n2; i++)
        {
            s3 += '1';
        }
        
        ans = s3 + ans;
        cout<<ans<<"\n";
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
