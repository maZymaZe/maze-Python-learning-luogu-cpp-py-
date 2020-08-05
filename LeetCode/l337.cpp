/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<TreeNode*,int> mp;
class Solution {
public:
    int rob(TreeNode* root) {
        mp.clear();
        return dp(root);
    }
    int dp(TreeNode* root){
        if(!root)return 0;
        if(mp.count(root))return mp[root];
        int a=root->val,b=0;
        if(root->left){
            auto p=root->left;
            b+=dp(p);
            a+=dp(p->left)+dp(p->right);
        }
        if(root->right){
            auto p=root->right;
            b+=dp(p);
            a+=dp(p->left)+dp(p->right);
        }
        int c=max(a,b);
        mp.insert({root,c});
        return c;
    }
};