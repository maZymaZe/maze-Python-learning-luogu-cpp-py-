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
class Solution {
public:
    bool ck(TreeNode *o,TreeNode *t){
        if(!o&&!t)return true;
        if((!o||!t)||(o->val!=t->val))return false;
        return ck(o->left,t->left)&&ck(o->right,t->right);    
    }
    bool dfs(TreeNode *o,TreeNode *t){
        if(!o)return false;
        return ck(o,t)||dfs(o->left,t)||dfs(o->right,t);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s,t);
    }
};