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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* node) {
        if (!node) return "N";

        string s = "";

        s += to_string(node->val);

        s += ":";
        s += serialize(node->left);
        s += serialize(node->right);

        return s;
    }

    int ptr = 0;

    TreeNode* _deserialize(string& data) {
        if (data[ptr] == 'N') {
            ptr++;
            return nullptr;
        }

        string num = "";

        while (data[ptr] != ':') {
            num += data[ptr];
            ptr++;
        }

        TreeNode* node = new TreeNode(stoi(num));

        ptr++;

        node->left = deserialize(data);
        node->right = deserialize(data);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return _deserialize(data);
    }
};
