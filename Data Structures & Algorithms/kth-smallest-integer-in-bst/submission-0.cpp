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
    vector<int> sorted;

    void dfs(TreeNode* node) {
        if (!node) return;

        dfs(node->left);

        sorted.push_back(node->val);

        dfs(node->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);

        return sorted[k-1];
    }
};
