#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[101][101];

void solve()
{
    ll p, q;
    cin>>p>>q;
    string s1, s2;
    cin>>s1>>s2;
    
    for(ll i=0; i<=p; i++)
    {
        dp[i][0] = i;
    }
    
    for(ll j=1; j<=q; j++)
    {
        dp[0][j] = j;
    }
    
    for(ll i=1; i<=p; i++)
    {
        for(ll j=1; j<=q; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                ll op1, op2, op3;
                op1 = 1+dp[i-1][j-1];
                op2 = 1+dp[i-1][j];
                op3 = 1+dp[i][j-1];
                dp[i][j] = min(op1, min(op2, op3));
            }
        }
    }
    
    cout<<dp[p][q]<<"\n";
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
