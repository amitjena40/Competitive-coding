/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return tree if passed  tree
// is balanced, else false.

int util(Node* root, bool* ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int h1 = util(root->left, ans);
    int h2 = util(root->right, ans);

    if (abs(h1 - h2) > 1)
    {
        *ans = false;
    }

    return max(h1, h2) + 1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    bool ans = true;
    util(root, &ans);
    return ans;
}