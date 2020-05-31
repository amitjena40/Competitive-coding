#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct jobs
{
	ll id, dead, profit;
};

bool cmp(jobs job1, jobs job2)
{
	return job1.profit > job2.profit;
}

void solve()
{
	ll n, max_time = INT_MIN;
	cin >> n;
	jobs job[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> job[i].id >> job[i].dead >> job[i].profit;
		if (job[i].dead > max_time)
		{
			max_time = job[i].dead;
		}
	}

	sort(job, job + n, cmp);
	bool hours[max_time];
	memset(hours, 0, sizeof(hours));
	ll count = 0, profit = 0;

	for (ll i = 0; i < n; i++)
	{
		ll slot = job[i].dead - 1;
		while (slot >= 0)
		{
			if (!hours[slot])
			{
				profit += job[i].profit;
				count++;
				hours[slot] = true;
				break;
			}
			slot--;
		}

		if (count == max_time)
		{
			break;
		}
	}
	cout << count << " " << profit << "\n";
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