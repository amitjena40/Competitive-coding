#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[101][101][101];

ll LCS(char *s1, char *s2, char *s3, ll n1, ll n2, ll n3)
{
    if(n1==0 || n2==0 || n3==0)
    {
        return 0;
    }
    
    if(dp[n1][n2][n3] > -1)
    {
        return dp[n1][n2][n3];
    }
    
    if(s1[0] == s2[0] && s2[0] == s3[0])
    {
        dp[n1][n2][n3] = 1 + LCS(s1 + 1, s2 + 1, s3 + 1, n1-1, n2-1, n3-1);
        return dp[n1][n2][n3];
    }
    else
    {
        ll option1 = LCS(s1, s2, s3+1, n1, n2, n3-1);
        ll option2 = LCS(s1, s2+1, s3, n1, n2-1, n3);
        ll option3 = LCS(s1+1, s2, s3, n1-1, n2, n3);
        dp[n1][n2][n3] = max(option1, max(option2, option3));
        return dp[n1][n2][n3];
    }
}

void solve()
{
    ll n, m, k;
    cin>>n>>m>>k;
    char s1[n+1], s2[m+1], s3[k+1];
    cin>>s1>>s2>>s3;
    memset(dp, -1, sizeof(dp));
    cout<<LCS(s1, s2, s3, n, m, k)<<"\n";
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
