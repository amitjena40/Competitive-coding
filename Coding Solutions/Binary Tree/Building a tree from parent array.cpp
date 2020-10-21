#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct Node
{
	ll val;
	Node* left;
	Node* right;
};

Node* getNode(ll val)
{
	Node *ptr = new Node;
	ptr->val = val;
	ptr->left = ptr->right = NULL;
	return ptr;
}

Node* createTree(vector<ll> parent, vector<ll> values)
{
	ll n = parent.size();
	unordered_map<ll, Node*> m;

	for (ll i = 0; i < n; i++)
	{
		m[i] = getNode(values[i]);
	}

	Node* root;
	for (ll i = 0; i < n; i++)
	{
		if (parent[i] == -1)
		{
			root = m[i];
		}
		else
		{
			Node* ptr = m[parent[i]];

			if (ptr->left)
			{
				ptr->right = m[i];
			}
			else
			{
				ptr->left = m[i];
			}
		}
	}

	return root;
}

ll util(Node *root, ll &ans)
{
	if (root == NULL)
	{
		return 0;
	}

	ll h1 = util(root->left, ans);
	ll h2 = util(root->right, ans);

	ans = max(ans, h1 + h2 + root->val);

	return max(h1, h2) + root->val;
}

void solve()
{
	ll n;
	cin >> n;

	vector<ll> parent(n);
	vector<ll> values(n);

	for (ll i = 0; i < n; i++)
	{
		cin >> parent[i];
	}

	for (ll i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	Node* root = createTree(parent, values);

	ll ans = 0;
	ll temp = util(root, ans);
	cout << ans << "\n";
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
	t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}