#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll dp[300][300];

ll coin_change(ll n, ll *d, ll numD)
{
    if(n==0)
      return 1;
      
    if(n<0)
      return 0;
      
    if(numD==0)
      return 0;
      
    if(dp[n][numD] > -1)
      return dp[n][numD];
      
    ll first = coin_change(n-d[0], d, numD);
    ll second = coin_change(n, d+1, numD-1);
    dp[n][numD] = first+second;
    return dp[n][numD];
}

int main()
{
     ll t;
     cin>>t;

     while(t--)
     {
         ll m, n;
         cin>>m;
         ll d[m];
         for(ll i=0; i<m; i++)
         {
             cin>>d[i];
         }
         
         cin>>n;
         
         //ll dp[n+1][m+1];
         for(ll i=0; i<=n; i++)
         {
             for(ll j=0; j<=m; j++)
             {
                 dp[i][j] = -1;
             }
         }
         
         cout<<coin_change(n, d, m)<<"\n";
     }
    return 0;
}
