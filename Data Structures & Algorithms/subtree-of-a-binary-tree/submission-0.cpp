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
    bool dfs(TreeNode* node, TreeNode* subRoot) {
        if (isEqual(node, subRoot)) return true;

        if (!node) return false;

        return dfs(node->left, subRoot) || dfs(node->right, subRoot);
    }

    bool isEqual(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isEqual(p->left, q->left) && isEqual(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);       
    }
};
