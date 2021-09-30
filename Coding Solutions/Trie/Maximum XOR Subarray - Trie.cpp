#include<bits/stdc++.h>
using namespace std;
#define ll long long

class trieNode
{
public:
    trieNode *left;
    trieNode *right;
};

void insert(ll n, trieNode *head)
{
    trieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int b = (n >> i) & 1;
        if (b == 0)
        {
            if (!curr->left)
                curr->left = new trieNode();
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
                curr->right = new trieNode();
            curr = curr->right;
        }
    }
}

ll MaxXorSubarray(trieNode *head, ll num)
{
    ll curr_xor = 0;
    trieNode* curr = head;
    for (int j = 31; j >= 0; j--)
    {
        int b = (num >> j) & 1;
        if (b == 0)
        {
            if (curr->right)
            {
                curr_xor += pow(2, j);
                curr = curr->right;
            }
            else
                curr = curr->left;
        }
        else
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr_xor += pow(2, j);
                curr = curr->right;
            }
        }
    }

    return num ^ curr_xor;
}

int main() {

    // Write your code here
    ll n;
    cin >> n;

    ll curr_xor = 0, maxXor = INT_MIN;

    trieNode *head = new trieNode();
    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        curr_xor = curr_xor ^ num;
        insert(curr_xor, head);
        maxXor = max(maxXor, MaxXorSubarray(head, curr_xor));
    }

    cout << maxXor;
    return 0;
}