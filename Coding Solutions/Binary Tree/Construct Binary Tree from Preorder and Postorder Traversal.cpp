/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* treeUtil(vector<int> &preorder, int preS, int preE, vector<int> &postorder, int posS, int posE) {
        if (preS > preE || posS > posE) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preS]);
        if (preS == preE || posS == posE) {
            return root;
        }

        int idx = -1;
        for (int i = posS; i <= posE; i++) {
            if (postorder[i] == preorder[preS + 1]) {
                idx = i;
                break;
            }
        }

        int lposS = posS;
        int lposE = idx;
        int rposS = idx + 1;
        int rposE = posE - 1;
        int lpreS = preS + 1;
        int lpreE = lpreS + lposE - lposS;
        int rpreS = lpreE + 1;
        int rpreE = preE;

        root->left = treeUtil(preorder, lpreS, lpreE, postorder, lposS, lposE);
        root->right = treeUtil(preorder, rpreS, rpreE, postorder, rposS, rposE);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return treeUtil(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};