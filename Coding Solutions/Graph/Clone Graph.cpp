/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> copy;
public:
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return NULL;
        }

        if (copy.find(node) == copy.end())
        {
            Node* temp = new Node(node->val, {});
            copy[node] = temp;
            for (auto it : node->neighbors)
            {
                temp->neighbors.push_back(cloneGraph(it));
            }
        }

        return copy[node];
    }
};