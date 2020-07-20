/*Complete the function below

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

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{
    //add code here.
    stack<Node* > st;
    Node* curr = root;
    int count = 0;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        count++;
        curr = st.top();
        st.pop();

        if (count == K)
        {
            return curr->data;
        }

        curr = curr->right;
    }
    return -1;
}