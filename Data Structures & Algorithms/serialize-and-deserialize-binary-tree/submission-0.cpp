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
        if (!node) return "#";

        string s = "";

        s += to_string(node->val);

        s += "(";
        s += serialize(node->left);
        s += ",";
        s += serialize(node->right);
        s += ")";

        cout << s << endl;

        return s;
    }

    int ptr = 0;

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[ptr] == '#') {
            ptr++;
            return nullptr;
        }

        string num = "";

        while (data[ptr] != '(') {
            num += data[ptr];
            ptr++;

        }

        TreeNode* node = new TreeNode(stoi(num));

        ptr++;

        node->left = deserialize(data);

        ptr++;

        node->right = deserialize(data);

        ptr++;

        return node;
    }
};
