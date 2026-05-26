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
    int best = -1e9;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int l = dfs(node->left);
        int r = dfs(node->right);

        best = max(best, l + r + node->val);

        return max(0, max(l, r) + node->val);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return best;
    }
};
