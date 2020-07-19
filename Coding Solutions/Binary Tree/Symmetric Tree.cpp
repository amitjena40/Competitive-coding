/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true/false denoting whether the tree is Symmetric or not

bool util(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if ((root1->data == root2->data) && util(root1->left, root2->right) && util(root1->right, root2->left))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool isSymmetric(struct Node* root)
{
    // Code here
    if (root == NULL)
    {
        return true;
    }
    return util(root->left, root->right);
}