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
    bool dfs(TreeNode* node, int min_allowed, int max_allowed) {
        if (!node) return true;
        if (node->val <= min_allowed) return false;
        if (node->val >= max_allowed) return false;

        return 
            dfs(node->left, min_allowed, node->val) && 
            dfs(node->right, node->val, max_allowed);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, -1e9, 1e9);
    }
};
