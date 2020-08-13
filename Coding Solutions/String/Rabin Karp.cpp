#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back
#define d 256

using namespace std;

void solve()
{
	string str, pat;
	cin >> str >> pat;

	ll p = 0, power = pow(d, pat.size() - 1), flag = 0;
	for (ll i = 0; i < pat.size(); i++)
	{
		p += pat[i] * power;
		power /= d;
	}

	ll curr_score = 0;
	for (ll i = 0; i < str.size() - pat.size() + 1; i++)
	{
		power = pow(d, pat.size() - 1);
		if (i == 0)
		{
			for (ll j = i; j < i + pat.size(); j++)
			{
				curr_score += str[j] * power;
				power /= d;
			}
		}
		else
		{
			curr_score = (curr_score - str[i - 1] * power) * d + str[i + pat.size() - 1];
		}

		if (curr_score == p)
		{
			ll j;
			for (j = i; j < i + pat.size(); j++)
			{
				if (str[j] != pat[j - i])
				{
					break;
				}
			}

			if (j == i + pat.size())
			{
				cout << "Match found at pos:" << i + 1 << "\n";
				flag = 1;
			}
		}
	}

	if (flag == 0)
		cout << "Match not found\n";
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