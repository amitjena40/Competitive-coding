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
    int util(TreeNode* root, int &result)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = util(root->left, result);
        int right = util(root->right, result);

        int case1 = max(max(left, right) + root->val, root->val);
        int case2 = max(left + right + root->val, case1);
        result = max(result, case2);

        return case1;
    }

    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        util(root, result);
        return result;
    }
};