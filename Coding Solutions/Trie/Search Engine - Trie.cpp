#include <bits/stdc++.h>
using namespace std;

class trieNode
{
public:
    trieNode** children;
    int weight;

    trieNode()
    {
        weight = 0;
        children = new trieNode*[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

void Insert(string s, int weight, trieNode* root)
{
    if (s.length() == 0)
    {
        return;
    }

    int index = s[0] - 'a';
    trieNode* child;

    if (root->children[index])
    {
        child = root->children[index];
    }
    else
    {
        child = new trieNode();
        root->children[index] = child;
    }

    root->weight = max(root->weight, weight);
    Insert(s.substr(1), weight, child);
}

int bestSearch(string s, trieNode* root)
{
    int ans = -1;
    trieNode* curr = root;
    for (int i = 0; i < s.length(); i++)
    {

        int index = s[i] - 'a';
        trieNode* child = curr->children[index];
        if (child)
        {
            ans = child->weight;
            curr = child;
        }
        else
        {
            return -1;
        }
    }

    return ans;
}


int main()
{
    int n, q;
    cin >> n >> q;

    trieNode *root = new trieNode();
    for (int i = 0; i < n; i++)
    {
        string s;
        int weight;
        cin >> s >> weight;
        Insert(s, weight, root);
    }

    for (int i = 0; i < q; i++)
    {
        string pre;
        cin >> pre;

        cout << bestSearch(pre, root) << "\n";
    }
    return 0;
}
