#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> m;
    int n = s.size();
    for (int len = 1; len <= s.size(); len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            string pat = s.substr(i, len);
            sort(pat.begin(), pat.end());
            m[pat]++;
        }
    }

    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int n = it->second;
        ans += n * (n - 1) / 2;
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
