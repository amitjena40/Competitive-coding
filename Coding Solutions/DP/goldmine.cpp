#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long


ll dp[50][50];

int main()
{
     ll t;
     cin>>t;
     //cout<<"Hi!"; 
     while(t--)
     {
         
         ll n, m;
         cin>>n>>m;
         for(ll i=0; i<=n; i++)
         {
             for(ll j=0; j<=m; j++)
             {
                 dp[i][j] = 0;
             }
         }
         
         ll M[n+1][m+1];
         for(ll i=1; i<=n; i++)
         {
             for(ll j=1; j<=m; j++)
             {
                 cin>>M[i][j];
             }
         }
         
         for(ll i=1; i<=n; i++)
         {
             dp[i][m] = M[i][m];
         }
         
         
         for(ll j=m-1; j>=1; j--)
         {
             for(ll i=1; i<=n; i++)
             {
                 ll first=0, second = 0, third=0;
                 if(i>=2)
                   first = dp[i-1][j+1];
                   
                   
                 second = dp[i][j+1];
                 
                 if(i<=n-1)
                   third = dp[i+1][j+1];
                  
                 dp[i][j] = M[i][j] + max(first, max(second, third));  
             }
         }
         
         
         
         ll max_gold = 0;
         for(ll i=1; i<=n; i++)
         {
             if(dp[i][1]>max_gold)
               max_gold = dp[i][1];
         }
         
         cout<<max_gold<<"\n";
     }
    return 0;
}
