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
    int pre_l = 0;

    unordered_map<int, int> um; 

    TreeNode* tree(int in_l, int in_r, vector<int>& preorder, vector<int>& inorder) {  
        if (in_l > in_r) return nullptr;

        int m = um[preorder[pre_l]];

        TreeNode* ans = new TreeNode(preorder[pre_l]);
        pre_l++;

        ans->left = tree(in_l, m-1, preorder, inorder);
        ans->right = tree(m+1, in_r, preorder, inorder);

        return ans;
    }   

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++) {
            um[inorder[i]] = i;
        }

        return tree(0, preorder.size()-1, preorder, inorder);
    }
};
