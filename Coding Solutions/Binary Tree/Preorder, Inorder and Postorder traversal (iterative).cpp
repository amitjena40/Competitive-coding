#include<bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node (int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

/* Iterative function for inorder tree
traversal */
void inOrder(struct Node *root)
{
	stack<Node *> s;
	Node *curr = root;

	while (curr != NULL || s.empty() == false)
	{
		/* Reach the left most Node of the
		curr Node */
		while (curr != NULL)
		{
			/* place pointer to a tree node on
			the stack before traversing
			the node's left subtree */
			s.push(curr);
			curr = curr->left;
		}

		/* Current must be NULL at this point */
		curr = s.top();
		s.pop();

		cout << curr->data << " ";

		/* we have visited the node and its
		left subtree. Now, it's right
		subtree's turn */
		curr = curr->right;

	} /* end of while */
}

void preOrder(Node *root)
{
	if (root == NULL)
		return;

	stack<Node*> st;

	// start from root node (set current node to root node)
	Node* curr = root;

	// run till stack is not empty or current is
	// not NULL
	while (!st.empty() || curr != NULL)
	{
		// Print left children while exist
		// and keep pushing right into the
		// stack.
		while (curr != NULL)
		{
			cout << curr->data << " ";

			if (curr->right)
				st.push(curr->right);

			curr = curr->left;
		}

		// We reach when curr is NULL, so We
		// take out a right child from stack
		if (st.empty() == false)
		{
			curr = st.top();
			st.pop();
		}
	}
}

void postOrder(Node* root)
{
	if (root == NULL)
		return;

	// Create two stacks
	stack<Node *> s1, s2;

	// push root to first stack
	s1.push(root);
	Node* node;

	// Run while first stack is not empty
	while (!s1.empty()) {
		// Pop an item from s1 and push it to s2
		node = s1.top();
		s1.pop();
		s2.push(node);

		// Push left and right children
		// of removed item to s1
		if (node->left)
			s1.push(node->left);
		if (node->right)
			s1.push(node->right);
	}

	// Print all elements of second stack
	while (!s2.empty()) {
		node = s2.top();
		s2.pop();
		cout << node->data << " ";
	}
}

/* Driver program to test above functions*/
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/* Constructed binary tree is
			1
			/ \
		2	 3
		/ \
	4	 5
	*/
	struct Node *root = new Node(1);
	root->left	 = new Node(2);
	root->right	 = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "Preorder traversal: ";
	preOrder(root);
	cout << "\n";
	cout << "Inorder traversal: ";
	inOrder(root);
	cout << "\n";
	cout << "Postorder traversal: ";
	postOrder(root);
	cout << "\n";
	return 0;
}
