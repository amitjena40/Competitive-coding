/* BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    if (root == NULL)return;

    if (root->key == key)
    {
        if (root->left)
        {
            Node* temp;
            temp = root->left;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            pre = temp;
        }

        if (root->right)
        {
            Node* temp;
            temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            suc = temp;
        }
    }
    else if (root->key < key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}