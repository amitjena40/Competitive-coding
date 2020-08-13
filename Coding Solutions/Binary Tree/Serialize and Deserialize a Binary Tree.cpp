/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*this  function serializes
the binary tree and stores
it in the vector A*/

int idx = 0;
void serialize(Node *root, vector<int> &A)
{
  //Your code here
  idx = 0;
  if (root == NULL)
  {
    A.push_back(-1);
    return;
  }

  A.push_back(root->data);
  serialize(root->left, A);
  serialize(root->right, A);
}

/*this function deserializes
 the serialized vector A*/


Node * deSerialize(vector<int> &A)
{
  //Your code here
  if (idx >= A.size() || A[idx] == -1)
  {
    idx++;
    return NULL;
  }

  Node* root = new Node(A[idx]);
  idx++;
  root->left = deSerialize(A);
  root->right = deSerialize(A);
  return root;
}