#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	if (n == 1)
	{
		cout << "1\n";
		return;
	}
	else if (n == 2)
	{
		cout << "11\n";
		return;
	}

	string ans = "", past_ans = "11";
	for (ll i = 3; i <= n; i++)
	{
		ll count = 1;
		ll j;
		for (j = 1; j < past_ans.size(); j++)
		{
			if (past_ans[j] != past_ans[j - 1])
			{
				ans += to_string(count);
				ans.PB(past_ans[j - 1]);
				count = 1;
			}
			else
				count++;
		}
		ans += to_string(count);
		ans.PB(past_ans[j - 1]);

		past_ans = ans;
		ans = "";
	}

	cout << past_ans << "\n";
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