#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

ll least_prime[1000001];

void leastPrimeFactor(ll n) 
{ 
 
    least_prime[1] = 1; 
  
    for (ll i = 2; i <= n; i++) 
    { 
        if (least_prime[i] == 0) 
        { 
            least_prime[i] = i; 

            for (ll j = 2*i; j <= n; j += i) 
                if (least_prime[j] == 0) 
                   least_prime[j] = i; 
        } 
    } 
}    


void solve()
{
    ll n, k, sum=0;
    cin>>n>>k;
    
    n = least_prime[n] + n + 2*(k-1);

    cout<<n<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    
    leastPrimeFactor(1000001);
    
    while(t--)
    {
        solve();
    }
    return 0;
}
