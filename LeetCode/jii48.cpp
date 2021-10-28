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
        queue<TreeNode*> qq;
        qq.push(root);
        string rt;
        while (!qq.empty()) {
            TreeNode* tmp = qq.front();
            qq.pop();
            if (tmp) {
                rt += "," + to_string(tmp->val);
                qq.push(tmp->left);
                qq.push(tmp->right);
            } else
                rt += ",";
        }
        rt += ",";
        return rt;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> store;
        int l = 0, r = 1, w = data.size();
        while (r < w && data[r] != ',')
            r++;

        while (r < w) {
            if (l - r != -1) {
                store.push_back(stoi(data.substr(l + 1, r - l - 1)));
            } else {
                store.push_back(-564);
            }
            l = r;
            r++;
            while (r < w && data[r] != ',')
                r++;
        }

        queue<TreeNode*> qq;
        if (store[0] == -564)
            return NULL;
        qq.push(new TreeNode(store[0]));
        auto rtt = qq.front();

        for (int i = 1; i < store.size();) {
            if (store[i] != -564) {
                TreeNode* p = new TreeNode(store[i]);
                qq.push(p);
                qq.front()->left = p;
            }
            i++;
            if (store[i] != -564) {
                TreeNode* p = new TreeNode(store[i]);
                qq.push(p);
                qq.front()->right = p;
            }
            i++;
            qq.pop();
        }
        return rtt;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));