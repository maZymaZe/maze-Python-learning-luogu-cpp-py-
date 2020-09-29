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
    vector<int> ans;
    stack<TreeNode*> s;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return ans;
        TreeNode* p = nullptr;
        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (root->right == nullptr || root->right == p) {
                ans.push_back(root->val);
                p = root;
                root = nullptr;
            } else {
                s.push(root);
                root = root->right;
            }
        }
        return ans;
    }
};