#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long


bool dp[1000000][101];

int main()
{
     ll t;
     cin>>t; 
     while(t--)
     {
         ll n;
         cin>>n;
         ll arr[n+1], sum=0;
         for(ll i=0; i<=n-1; i++)
         {
             cin>>arr[i];
             sum += arr[i];
         }
         
         if(sum%2!=0)
         {
             cout<<"NO\n";
         }
         else
         {
             for(ll i=0; i<=sum/2; i++)
             {
                 for(ll j=0; j<=n; j++)
                 {
                     dp[i][j] = false;
                 }
             }
             
             for(ll j=0; j<=n; j++)
             {
                 dp[0][j] = true;
             }
             
             for(ll i=1; i<=sum/2; i++)
             {
                 dp[i][0] = false;
             }
             
             for(ll i=1; i<=sum/2; i++)
             {
                 for(ll j=1; j<=n; j++)
                 {
                     dp[i][j] = dp[i][j-1];
                     if(i>=arr[j-1])
                     {
                         dp[i][j] = dp[i][j-1] || dp[i-arr[j-1]][j-1];
                     }
                 }
             }
             
             if(dp[sum/2][n])
             {
                 cout<<"YES\n";
             }
             else
             {
                 cout<<"NO\n";
             }
         }
     }
    return 0;
}
