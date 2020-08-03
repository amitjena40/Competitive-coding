#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool fn(string s, ll prev)
{
    ll n = s.size();

    if (s[0] == '0')
    {
        return false;
    }

    ll curr_val = 0;
    for (ll i = 0; i < n; i++)
    {
        curr_val = curr_val * 10 + s[i] - '0';
    }

    if (curr_val == prev + 1)
    {
        return true;
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll num = 0;

        for (ll j = 0; j <= i; j++)
        {
            num = num * 10 + s[j] - '0';
        }

        if (num != prev + 1)
        {
            continue;
        }

        if (fn(s.substr(i + 1, n - i - 1), num))
        {
            return true;
        }
    }

    return false;
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    ll n = s.size();
    if (s[0] == '0')
    {
        if (fn(s.substr(1, n - 1), 0))
        {
            cout << "YES " << 0 << "\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    else
        for (ll i = 0; i < n - 1; i++)
        {
            ll num = 0;
            for (ll j = 0; j <= i; j++)
            {
                num = num * 10 + s[j] - '0';
            }
            if (fn(s.substr(i + 1, n - i - 1), num))
            {
                cout << "YES " << num << "\n";
                return;
            }
        }

    cout << "NO\n";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
