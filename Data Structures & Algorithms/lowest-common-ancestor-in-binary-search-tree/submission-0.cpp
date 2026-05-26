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
    TreeNode* lca(TreeNode* node, int v1, int v2) {
        if (v1 > v2) return lca(node, v2, v1);

        if (v1 <= node->val && node->val <= v2) return node;

        if (v1 > node->val) return lca(node->right, v1, v2);

        return lca(node->left, v1, v2);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p->val, q->val);
    }
};
