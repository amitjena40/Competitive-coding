/*Complete the function below
Node is as follows
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

// root : the root Node of the given BST
// target : the target sum
bool isPairPresent(struct Node *root, int target)
{
//add code here.
    stack<Node*> s1;
    stack<Node*> s2;

    Node* curr1 = root;
    Node* curr2 = root;

    while (true)
    {
        while (curr1)
        {
            s1.push(curr1);
            curr1 = curr1->left;
        }

        while (curr2)
        {
            s2.push(curr2);
            curr2 = curr2->right;
        }

        if (s1.empty() || s2.empty())
        {
            break;
        }

        curr1 = s1.top();
        curr2 = s2.top();

        if (curr1->data + curr2->data == target)
        {
            if (curr1 == curr2) return false;

            return true;
        }
        else if (curr1->data + curr2->data < target)
        {
            s1.pop();
            curr1 = curr1->right;
            curr2 = NULL;
        }
        else
        {
            s2.pop();
            curr2 = curr2->left;
            curr1 = NULL;
        }
    }

    return false;
}