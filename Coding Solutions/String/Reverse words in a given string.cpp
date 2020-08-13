#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

void solve()
{
	string s;
	cin >> s;
	s.PB('.');
	string word = "";
	stack<string> st;
	for (ll i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			st.push(word);
			word = "";
			continue;
		}

		word.PB(s[i]);
	}

	while (st.size() != 1)
	{
		cout << st.top() << ".";
		st.pop();
	}
	cout << st.top() << "\n";
	st.pop();
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