#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	stack<char> brackets;
	for (ll i = 0; i < s.size(); i++)
	{
		if (brackets.empty())
		{
			brackets.push(s[i]);
		}
		else if ((s[i] == '}' and brackets.top() == '{') or (s[i] == ']' and brackets.top() == '[') or (s[i] == ')' and brackets.top() == '('))
		{
			brackets.pop();
		}
		else
		{
			brackets.push(s[i]);
		}
	}

	if (brackets.empty())
	{
		cout << "balanced\n";
	}
	else
	{
		cout << "not balanced\n";
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