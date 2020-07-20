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

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
struct info
{
    int sz;
    int mx;
    int mn;
    int ans;
    bool isBST;
};

info util(Node* root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    info l = util(root->left);
    info r = util(root->right);

    info final;
    final.sz = 1 + l.sz + r.sz;

    if (l.isBST && r.isBST && l.mx < root->data && root->data < r.mn)
    {
        final.mx = max(root->data, r.mx);
        final.mn = min(root->data, l.mn);
        final.ans = final.sz;
        final.isBST = true;
        return final;
    }

    final.ans = max(l.ans, r.ans);
    final.isBST = false;
    return final;
}

int largestBst(Node *root)
{
    //Your code here
    info final = util(root);
    return final.ans;
}