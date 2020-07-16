#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define PB push_back

using namespace std;

struct Node
{
	ll data;
	Node* left;
	Node *right;
};

Node* getNewNode(ll data)
{
	Node* newNode = new Node();
	newNode->left = newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

Node* Insert(Node* root, ll data)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}

	return root;
}

void Preorder(Node* root)
{
	if (root == NULL)return;
	cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(Node* root)
{
	if (root == NULL)return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

void Postorder(Node* root)
{
	if (root == NULL)return;
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data << " ";
}

void solve()
{
	Node* root = NULL;
	root = Insert(root, 5);
	root = Insert(root, 6);
	root = Insert(root, 7);
	root = Insert(root, 1);
	root = Insert(root, 2);
	root = Insert(root, 3);
	root = Insert(root, 4);

	cout << "\nPreorder traversal: ";
	Preorder(root);

	cout << "\nInorder traversal: ";
	Inorder(root);

	cout << "\nPostorder traversal: ";
	Postorder(root);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}