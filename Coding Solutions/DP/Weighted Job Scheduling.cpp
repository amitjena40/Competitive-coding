#include <bits/stdc++.h>
#define ll long long
#define mod 1e9+7
#define PB push_back

using namespace std;

ll dp[1001];

struct jobs
{
	ll start, finish, profit;
};

bool cmp(jobs job1, jobs job2)
{
	return job1.start < job2.start;
}

ll fn(ll idx, jobs job[], ll n)
{
	if (dp[idx] != -1)
	{
		return dp[idx];
	}

	ll maxp = job[idx].profit;
	for (ll i = idx + 1; i < n; i++)
	{
		if (job[idx].finish <= job[i].start)
		{
			maxp = max(maxp, job[idx].profit + fn(i, job, n));
		}
	}
	dp[idx] = maxp;
	return dp[idx];
}

void solve()
{
	ll n;
	cin >> n;
	jobs job[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> job[i].start >> job[i].finish >> job[i].profit;
	}

	sort(job, job + n, cmp);
	memset(dp, -1, sizeof(dp));
	dp[n - 1] = job[n - 1].profit;
	ll ans = fn(0, job, n);

	ll max_ans = 0;
	for (ll i = 0; i < n; i++)
	{
		max_ans = max(max_ans, dp[i]);
	}
	cout << max_ans << "\n";
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