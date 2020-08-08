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
bool f1,f2;
int v1,v2,v3,v4;
TreeNode *p,*p1,*p2,*p3,*p4;
int pre;
void dfs(TreeNode* root){
    if(!root)return;
    dfs(root->left);
    if(root->val>=pre)pre=root->val,p=root;
    else{
        if(!f1)v1=pre,v2=root->val,f1=1,p1=p,p2=root;
        else if(!f2)v3=pre,v4=root->val,f2=1,p3=p,p4=root;
        pre=root->val,p=root;
    }
    dfs(root->right);
}


class Solution {
public:
    void recoverTree(TreeNode* root) {
        f1=f2=false;
        v1=v2=v3=v4=0;
        p=p1=p2=p3=p4=0;
        pre=INT_MIN;
        dfs(root);
        if(f2){
            (*p4).val=v1;
            (*p1).val=v4;
        }
        else if(f1){
            (*p1).val=v2;
            (*p2).val=v1;
        }
        return;
    }
};