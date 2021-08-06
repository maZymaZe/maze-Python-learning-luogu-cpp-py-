/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<TreeNode*> ans;
    unordered_set<int> td;

    void dfsr(TreeNode* root, int f) {
        if (!root)
            return;
        if (td.count(root->val)) {
            dfsr(root->left, 1);
            dfsr(root->right, 1);
            return;
        }
        if (root->left) {
            if (td.count(root->left->val)) {
                dfsr(root->left, 1);
                root->left = nullptr;
            } else
                dfsr(root->left, 0);
        }
        if (root->right) {
            if (td.count(root->right->val)) {
                dfsr(root->right, 1);
                root->right = nullptr;
            } else
                dfsr(root->right, 0);
        }
        if (f)
            ans.push_back(root);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            td.insert(i);
        dfsr(root, 1);
        return ans;
    }
};