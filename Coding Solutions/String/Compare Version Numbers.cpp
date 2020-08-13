#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

int compareVersion(string version1, string version2) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < version1.size(); i++)
	{
		if (version1[i] == '.')
		{
			count1++;
		}
	}

	for (int i = 0; i < version2.size(); i++)
	{
		if (version2[i] == '.')
		{
			count2++;
		}
	}

	ll flag = 0;
	if (count1 > count2)
	{
		swap(version1, version2);
		swap(count1, count2);
		flag = 1;
	}

	while (count1 != count2)
	{
		version1 += ".0";
		count1++;
	}

	if (flag)
	{
		swap(version1, version2);
	}

	int id1 = 0, id2 = 0;
	for (; id1 < version1.size() && id2 < version2.size();)
	{
		int num1 = 0;
		while (id1 < version1.size() && version1[id1] != '.')
		{
			num1 = num1 * 10 + (version1[id1] - '0');
			id1++;
		}
		id1++;

		int num2 = 0;
		while (id2 < version2.size() && version2[id2] != '.')
		{
			num2 = num2 * 10 + (version2[id2] - '0');
			id2++;
		}
		id2++;

		if (num1 > num2)
		{
			return 1;
		}
		else if (num1 < num2)
		{
			return -1;
		}
	}

	return 0;
}

void solve()
{
	string s1, s2;
	cin >> s1 >> s2;

	cout << compareVersion(s1, s2) << "\n";
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


//Same concept but better code
int compareVersion(string version1, string version2) {
	int i = 0;
	int j = 0;
	int n1 = version1.size();
	int n2 = version2.size();

	int num1 = 0;
	int num2 = 0;
	while (i < n1 || j < n2)
	{
		while (i < n1 && version1[i] != '.') {
			num1 = num1 * 10 + (version1[i] - '0');
			i++;
		}

		while (j < n2 && version2[j] != '.') {
			num2 = num2 * 10 + (version2[j] - '0');;
			j++;
		}

		if (num1 > num2) return 1;
		else if (num1 < num2) return -1;

		num1 = 0;
		num2 = 0;
		i++;
		j++;
	}

	return 0;
}