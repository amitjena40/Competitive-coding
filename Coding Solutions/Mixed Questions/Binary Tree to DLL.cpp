/* Structure for tree and linked list

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

// This function should return head to the DLL

void bToDLLUtil(Node* root, Node* &head, Node* &prev)
{
    if (root == NULL)
    {
        return;
    }
    bToDLLUtil(root->left, head, prev);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    bToDLLUtil(root->right, head, prev);
}

Node * bToDLL(Node *root)
{
    // your code here
    Node* head = NULL;
    Node* prev = NULL;
    bToDLLUtil(root, head, prev);
    return head;
}