#include <bits/stdc++.h>
using namespace std;

class trieNode
{
public:
    trieNode** children;

    trieNode()
    {
        children = new trieNode*[27];
        for (int i = 0; i < 27; i++)
        {
            children[i] = NULL;
        }
    }
};

void Insert(string s, trieNode* root)
{
    if (s.empty())
    {
        root->children[26] = new trieNode();
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

    Insert(s.substr(1), child);
}

void displayWords(string pre, trieNode* curr)
{
    if (curr->children[26])
    {
        cout << pre << "\n";
    }

    for (int i = 0; i < 26; i++)
    {
        if (curr->children[i])
        {
            displayWords(pre + char(i + 'a'), curr->children[i]);
        }
    }
}

void Query(string pre, trieNode* root)
{
    trieNode* curr = root;
    for (int i = 0; i < pre.length(); i++)
    {
        int index = pre[i] - 'a';
        if (curr->children[index])
        {
            curr = curr->children[index];
        }
        else
        {
            Insert(pre, root);
            cout << "No suggestions\n";
            return;
        }
    }

    displayWords(pre, curr);
}

int main()
{
    int n;
    cin >> n;
    trieNode* head = new trieNode();
    while (n--)
    {
        string s;
        cin >> s;
        Insert(s, head);
    }

    int q;
    cin >> q;
    while (q--)
    {
        string pre;
        cin >> pre;
        Query(pre, head);
    }
    return 0;
}
