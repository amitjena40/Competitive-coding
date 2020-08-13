#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	priority_queue <ll> mx;
	priority_queue <ll, vector<ll>, greater<ll>> mn;
	ll median = 0;
	for (ll i = 0; i < n; i++)
	{
		ll item;
		cin >> item;
		if (i == 0)
		{
			mx.push(item);
			median = item;
		}
		else
		{
			if (item < median)
			{
				mx.push(item);
			}
			else
			{
				mn.push(item);
			}

			if (mx.size() - mn.size() >= 2)
			{
				if (mx.size() < mn.size())
				{
					mx.push(mn.top());
					mn.pop();
				}
				else
				{
					mn.push(mx.top());
					mx.pop();
				}
			}

			if (mx.size() > mn.size())
			{
				median = mx.top();
			}
			else if (mx.size() < mn.size())
			{
				median = mn.top();
			}
			else
			{
				median = (mx.top() + mn.top()) / 2;
			}
		}
		cout << median << "\n";
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
	//ll t;
	//cin >> t;
	//while (t--)
	//{
	solve();
	//}
	return 0;
}