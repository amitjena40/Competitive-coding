#define mod 1000000007

using namespace std;

ll dp[1001][1001];

void solve()
{
    ll n, w;
    cin>>n>>w;
    ll cost[n];
    vector<ll> wt, val;
    for(ll i=0; i<n; i++)
    {
        cin>>cost[i];
        if(cost[i]!=-1)
        {
            val.push_back(cost[i]);
            wt.push_back(i+1);
        }
    }
    
    n = val.size();
    memset(dp, 0, sizeof(dp));
    for(ll j=0; j<=w; j++)
    {
        dp[0][j] = INT_MAX;
    }
    
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=w; j++)
        {
            if(wt[i-1]>j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    
    if(dp[n][w]==INT_MAX)
    {
        cout<<"-1"<<"\n";
    }
    else
    {
        cout<<dp[n][w]<<"\n";
    }
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
