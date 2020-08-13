/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes

void connect(Node *p)
{
  // Your Code Here
  if (p == NULL)
  {
    return;
  }

  queue<pair<Node*, int>> q;
  int level = 0;
  q.push(make_pair(p, level));
  pair<Node*, int> prev;
  bool prevEmpty = true;
  while (!q.empty())
  {
    pair<Node*, int> curr;
    curr = q.front();
    q.pop();
    if (prevEmpty)
    {
      prev = curr;
      prevEmpty = false;
    }
    else
    {
      if (curr.second == prev.second)
      {
        prev.first->nextRight = curr.first;
      }
      else
      {
        prev.first->nextRight = NULL;
      }
      prev = curr;
    }

    if (curr.first->left)
    {
      q.push(make_pair(curr.first->left, curr.second + 1));
    }

    if (curr.first->right)
    {
      q.push(make_pair(curr.first->right, curr.second + 1));
    }
  }
  prev.first->nextRight = NULL;
}
