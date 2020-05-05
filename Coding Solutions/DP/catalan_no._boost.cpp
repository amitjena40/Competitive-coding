#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
using namespace std;

#define mod 1000000007
#define ll long long


cpp_int dp[101];

int main()
{
     ll t;
     cin>>t; 
     dp[0] = dp[1] = 1;
     
     for(ll i=2; i<=100; i++)
     {
         dp[i] = 0;
         for(ll j=0; j<i; j++)
         {
             dp[i] = dp[i] + dp[j]*dp[i-j-1];
         }
     }
     
     while(t--)
     {
         ll n;
         cin>>n;
         cout<<dp[n]<<"\n";
     }
    return 0;
}
