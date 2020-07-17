//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
  //Your code here
  if (root == NULL)
  {
    return;
  }

  queue<pair<Node*, int>> q;
  map<int, int> m;
  q.push(make_pair(root, 0));
  while (!q.empty())
  {
    pair<Node*, int> temp;
    temp = q.front();
    if (!m[temp.second])
      m[temp.second] = temp.first->data;
    if (temp.first->left)
    {
      q.push(make_pair(temp.first->left, temp.second - 1));
    }

    if (temp.first->right)
    {
      q.push(make_pair(temp.first->right, temp.second + 1));
    }
    q.pop();
  }

  for (auto it = m.begin(); it != m.end(); it++)
  {
    cout << it->second << " ";
  }
}