/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

Node* util(int in[], int pre[], int inS, int inE, int preS, int preE, int n)
{
    if (inS > inS || preS > preE)
    {
        return NULL;
    }

    Node *root = new Node(pre[preS]);
    int rootIdx = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == root->data)
        {
            rootIdx = i;
            break;
        }
    }

    int lpreS, lpreE, linS, linE, rpreS, rpreE, rinS, rinE;

    linS = inS;
    linE = rootIdx - 1;
    rinS = rootIdx + 1;
    rinE = inE;
    lpreS = preS + 1;
    lpreE = lpreS + linE - linS;
    rpreS = lpreE + 1;
    rpreE = preE;

    root->left = util(in, pre, linS, linE, lpreS, lpreE, n);
    root->right = util(in, pre, rinS, rinE, rpreS, rpreE, n);
    return root;
}

Node* buildTree(int in[], int pre[], int n)
{
//add code here.
    return util(in, pre, 0, n - 1, 0, n - 1, n);
}