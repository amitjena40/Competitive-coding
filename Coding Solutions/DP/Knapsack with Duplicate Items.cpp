#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

ll dp[1001][1001];

struct items
{
    ll val, wt;
};

bool cmp(items i1, items i2)
{
    return (i1.val/i1.wt)<(i2.val/i2.wt);
}

ll knapsack(ll w, items item[], ll n)
{
    if(n==0)
    {
        return 0;
    }
    else if(w<0)
    {
        return INT_MIN;
    }
    else if(dp[w][n]>-1)
    {
        return dp[w][n];
    }
    else
    {
        ll op1 = knapsack(w-item[0].wt, item, n)+item[0].val;
        ll op2 = knapsack(w, item+1, n-1);
        dp[w][n] = max(op1, op2);
        return dp[w][n];
    }
}

void solve()
{
    ll n, w;
    cin>>n>>w;
    items item[n];
    for(ll i=0; i<n; i++)
    {
        cin>>item[i].val;
    }
    
    for(ll i=0; i<n; i++)
    {
        cin>>item[i].wt;
    }
    
    sort(item, item+n, cmp);
    
    memset(dp, -1, sizeof(dp));
    cout<<knapsack(w, item, n)<<"\n";
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
