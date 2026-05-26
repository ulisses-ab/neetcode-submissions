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

    TreeNode* tree(int in_l, int in_r, vector<int>& preorder, vector<int>& inorder) {  
        if (in_l > in_r) return nullptr;

        int m;
        
        for (int i = in_l; i <= in_r; i++) {
            if (inorder[i] == preorder[pre_l]) {
                m = i;
                break;
            }
        }

        TreeNode* ans = new TreeNode(preorder[pre_l]);
        pre_l++;

        ans->left = tree(in_l, m-1, preorder, inorder);
        ans->right = tree(m+1, in_r, preorder, inorder);

        return ans;
    }   

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree(0, preorder.size()-1, preorder, inorder);
    }
};
