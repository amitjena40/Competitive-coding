#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

bool dp[1000];

bool dictCompare(string ans, string dict[], ll n)
{
    for(ll i=0; i<n; i++)
    {
        if(dict[i].compare(ans)==0)
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string ans, string dict[], ll n)
{
    ll size = ans.size();
    if(size==0)
    {
        return true;
    }
    
    for(ll i=1; i<=size; i++)
    {
        if(dp[i]==false && dictCompare(ans.substr(0, i), dict, n))
        {
            dp[i] = true;
        }
        
        if(dp[i]==true)
        {
            if(i==size)
            {
                return true;
            }
            
            for(ll j=i+1; j<=size; j++)
            {
                if(dp[j]==false && dictCompare(ans.substr(i, j-i), dict, n))
                   dp[j] = true;
                   
                if(dp[j]==true && j==size)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void solve()
{
    ll n;
    cin>>n;
    string dictionary[n];
    for(ll i=0; i<n; i++)
    {
        cin>>dictionary[i];
    }
    
    string ans;
    cin>>ans;
    memset(dp, 0, sizeof(dp));
    if(wordBreak(ans, dictionary, n))
      cout<<"1\n";
    else
      cout<<"0\n";
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
