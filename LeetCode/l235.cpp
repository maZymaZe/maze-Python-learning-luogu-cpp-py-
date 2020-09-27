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
    bool flag=false;
    TreeNode* ans=NULL;
    TreeNode* a1; TreeNode* a2;
    unordered_map<TreeNode*,TreeNode*> mp;
    unordered_set<TreeNode*> vis;
    TreeNode* f(TreeNode* root){
        if(!mp.count(root))mp.insert({root,root});
        if(mp[root]==root)return root;
        return mp[root]=f(mp[root]);
    }
    void tarjan(TreeNode* root){
        if(flag)return;
        if(!root)return;
        mp[root]=root;
        if(root->left)tarjan(root->left),mp[root->left]=f(root),vis.insert(root->left);
        if(root->right)tarjan(root->right),mp[root->right]=f(root),vis.insert(root->right);
        
        if(root==a1&&(vis.count(a2))){
            ans=mp[a2];flag=true;
        }else if(vis.count(a1)&&root==a2){
            ans=mp[a1];flag=true;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a1=p,a2=q;
        vis.insert(root);
        tarjan(root);
        return ans;
    }
};