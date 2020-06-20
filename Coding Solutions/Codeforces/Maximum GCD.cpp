#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	ll count[n + 1] = {0};

	for (ll i = 1; i <= n; i++)
	{
		count[i]++;
	}

	ll counter = 0;
	ll flag = 0;
	for (ll i = n; i >= 1; i--)
	{
		ll j = i;
		counter = 0;
		while (j <= n)
		{

			if (count[j] >= 2)
			{
				cout << j << "\n";
				flag = 1;
				break;
			}

			else if (count[j] == 1)
				counter++;

			j += i;

			if (counter == 2)
			{
				cout << i << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

//Better Answer is:
// Ans = n/2