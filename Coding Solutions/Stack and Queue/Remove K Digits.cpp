#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

string removeKdigits(string num, int k) {
    stack<char> s;
    for (auto x : num)
    {
        while (!s.empty() and s.top() > x and k > 0)
        {
            s.pop();
            k--;
        }

        if (!s.empty() || x != '0')
        {
            s.push(x);
        }
    }

    while (!s.empty() and k--)
    {
        s.pop();
    }

    if (s.empty())
    {
        return "0";
    }

    string ans = "";
    while (!s.empty())
    {
        char c = s.top();
        ans.insert(ans.begin(), c);
        s.pop();
    }

    return ans;
}

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    cout << removeKdigits(s, k) << "\n";
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
