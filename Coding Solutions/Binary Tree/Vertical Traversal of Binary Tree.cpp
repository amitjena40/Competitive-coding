/* A binary tree node has data, pointer to left child
   and a pointer to right child
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

void util(Node* root, map<int, vector<int>> &m)
{
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();
        m[p.second].push_back(p.first->data);
        if (p.first->left)
            q.push({p.first->left, p.second - 1});

        if (p.first->right)
            q.push({p.first->right, p.second + 1});
    }
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    //Your code here
    map<int, vector<int>> m;
    util(root, m);
    vector<int> ans;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        for (auto x : it->second)
        {
            ans.push_back(x);
        }
    }

    return ans;
}