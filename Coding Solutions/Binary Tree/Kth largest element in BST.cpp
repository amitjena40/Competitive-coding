/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
    //Your code here
    stack<Node*> st;
    Node* curr = root;
    int count = 0;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->right;
        }

        curr = st.top();
        st.pop();

        count++;
        if (count == K)
        {
            return curr->data;
        }

        curr = curr->left;
    }
}