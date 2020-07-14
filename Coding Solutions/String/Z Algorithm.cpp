#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string str, pat;
	cin >> str >> pat;

	string s = pat + "$" + str;
	ll z[s.size()];

	ll left = 0, right = 0;
	z[0] = 0;
	for (ll k = 1; k < s.size(); k++)
	{
		if (k > right)
		{
			left = right = k;
			while (right < s.size() && s[right] == s[right - left])
			{
				right++;
			}
			z[k] = right - left;
			right--;
		}
		else
		{
			ll k1 = k - left;
			if (k + z[k1] <= right)
			{
				z[k] = z[k1];
			}
			else
			{
				left = right = k;
				while (right < s.size() && s[right] == s[right - left])
				{
					right++;
				}
				z[k] = right - left;
				right--;
			}
		}
	}

	ll flag = 0;
	for (ll i = 0; i < s.size(); i++)
	{
		if (z[i] == pat.size())
		{
			cout << "Match Found at pos: " << i - pat.size() << "\n";
			flag = 1;
		}
	}

	if (flag == 0)
	{
		cout << "Match not found!\n";
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