/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// return the Height of the given Binary Tree
// Here leaf nodes are considered to have height 1;
int height(Node* root)
{
  // Your code here
  if (root == NULL)
  {
    return 0;
  }

  int h1 = height(root->left);
  int h2 = height(root->right);

  return max(h1, h2) + 1;
}
