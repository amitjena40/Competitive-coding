/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
  // Your Code Here
  vector<int> ans;
  if (root == NULL)
  {
    return ans;
  }

  queue<pair<Node*, int>> q;
  map<int, int> m;
  q.push(make_pair(root, 0));
  while (!q.empty())
  {
    pair<Node*, int> temp;
    temp = q.front();
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
    ans.push_back(it->second);
  }

  return ans;
}