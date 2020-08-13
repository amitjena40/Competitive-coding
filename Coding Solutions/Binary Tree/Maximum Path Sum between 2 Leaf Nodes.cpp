/*
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

int util(Node* root, int &result)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    int left = util(root->left, result);
    int right = util(root->right, result);

    if (root->left && root->right)
    {
        result = max(result, left + right + root->data);

        return max(left, right) + root->data;
    }

    return (root->left == NULL) ? right + root->data : left + root->data;
}

int maxPathSum(Node* root)
{
    // code here
    int result = INT_MIN;
    util(root, result);
    return result;
}