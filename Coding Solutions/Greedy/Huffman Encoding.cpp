#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct Node
{
	ll data;
	Node *left, *right;
	Node(ll x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct cmp
{
	bool operator()(Node *a, Node *b)
	{
		return  a->data > b->data;
	}
};

void print_tree(Node *root, string str)
{
	if (root->left == NULL && root->right == NULL)
	{
		cout << str << " ";
		return;
	}

	print_tree(root->left, str + "0");
	print_tree(root->right, str + "1");
}

void solve()
{
	string s;
	cin >> s;
	ll n = s.size();
	ll a[n];
	priority_queue<Node*, vector<Node*>, cmp> pq;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		Node *newnode = new Node(a[i]);
		pq.push(newnode);
	}

	while (pq.size() != 1)
	{
		Node *left = pq.top();
		pq.pop();
		Node *right = pq.top();
		pq.pop();
		Node *root = new Node(left->data + right->data);
		root->left = left;
		root->right = right;
		pq.push(root);
	}

	Node *root = pq.top();
	string str = "";
	print_tree(root, str);
	cout << "\n";
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