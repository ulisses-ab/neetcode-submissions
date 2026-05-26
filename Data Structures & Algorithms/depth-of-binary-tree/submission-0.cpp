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
    int get_depth(TreeNode* node) {
        if (!node) return 0;

        return max(get_depth(node->left), get_depth(node->right)) + 1;
    }

    int maxDepth(TreeNode* root) {
        return get_depth(root);
    }
};
