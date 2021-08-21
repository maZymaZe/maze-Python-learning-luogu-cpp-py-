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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!root->left)
            return root;
        TreeNode *l = root->left, *r = root->right;
        TreeNode* res = upsideDownBinaryTree(root->left);
        root->left = root->right = 0;

        l->right = root;
        l->left = r;
        return res;
    }
};