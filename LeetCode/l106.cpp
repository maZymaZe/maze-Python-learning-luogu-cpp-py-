/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int len;
    TreeNode* work(int l,
              int r,
              int ll,
              int rr,
              vector<int>& inorder,
              vector<int>& postorder) {
        if (l > r)
            return NULL;
        TreeNode* root = new TreeNode(postorder[rr]);
        for (int i = l; i <= r; i++) {
            if (inorder[i] == postorder[rr]) {
                root->left =
                    work(l, i - 1, ll, i - 1 - l + ll, inorder, postorder);
                root->right =
                    work(i + 1, r, i - l + ll, rr - 1, inorder, postorder);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        len = inorder.size();
        return work(0, len - 1, 0, len - 1, inorder, postorder);
    }
};