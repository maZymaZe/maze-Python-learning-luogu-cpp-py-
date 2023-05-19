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
struct PACK {
    int valid, mi, ma, sum;
};
class Solution {
   public:
    int ans = 0;
    PACK dfs(TreeNode* x) {
        if (!x) {
            return {2, 0, 0, 0};
        }
        PACK l = dfs(x->left), r = dfs(x->right);
        int ok = 1, tot = x->val, mi = x->val, ma = x->val;
        if (!l.valid || !r.valid) {
            return {0, 0, 0, 0};
        }
        if (l.valid == 1) {
            if (x->val > l.ma) {
                mi = l.mi, tot += l.sum;
            } else
                ok = 0;
        }
        if (r.valid == 1) {
            if (x->val < r.mi) {
                ma = r.ma, tot += r.sum;
            } else
                ok = 0;
        }
        if (!ok)
            return {0, 0, 0, 0};
        else
            ans = max(ans, tot);
        return {ok, mi, ma, tot};
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};