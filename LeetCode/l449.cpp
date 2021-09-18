/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        return to_string(root->val) + '(' + serialize(root->left) + ")(" +
               serialize(root->right) + ')';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int l = data.size();
        if (l == 0)
            return nullptr;
        for (int i = 0; i < l; i++) {
            if (data[i] == '(') {
                int c = 1;
                for (int j = i + 1; j < l; j++) {
                    if (data[j] == '(')
                        c++;
                    else if (data[j] == ')')
                        c--;
                    if (c == 0) {
                        TreeNode* root = new TreeNode(stoi(data.substr(0, i)));
                        root->left = deserialize(data.substr(i + 1, j - i - 1));
                        root->right =
                            deserialize(data.substr(j + 2, l - 1 - j - 2));
                        return root;
                    }
                }
            }
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;