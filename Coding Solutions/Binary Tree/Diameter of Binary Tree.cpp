/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

/* Computes the diameter of binary tree with given root.  */
int util(Node* root, int* d)
{
    if (root == NULL)
    {
        return 0;
    }

    int h1 = util(root->left, d);
    int h2 = util(root->right, d);

    *d = max(*d, h1 + h2 + 1);
    return max(h1, h2) + 1;
}

int diameter(Node* root) {
    // Your code here
    int d = 0;
    util(root, &d);
    return d;
}