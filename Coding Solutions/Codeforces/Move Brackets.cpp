#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	ll n;
	cin >> n;
	string str;
	cin >> str;
	stack<char> s;
	for (ll i = 0; i < str.size(); ++i)
	{
		if (s.empty())
		{
			s.push(str[i]);
		}
		else if (str[i] == ')' and s.top() == '(')
		{
			s.pop();
		}
		else
		{
			s.push(str[i]);
		}
	}

	cout << s.size() / 2 << "\n";
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