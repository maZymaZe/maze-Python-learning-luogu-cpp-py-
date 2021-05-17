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
    int xx, yy,lv1=-1,lv2=-1;
    TreeNode* fa1=nullptr,*fa2=nullptr;
    void dfs(TreeNode* root, TreeNode*fa,int lv){
        if(!root)return;
        if(root->val==xx||root->val==yy){
            if(lv1==-1){
                lv1=lv,fa1=fa;
            }else{
                lv2=lv,fa2=fa;
            }
        }
        dfs(root->left,root,lv+1);
        dfs(root->right,root,lv+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        xx=x,yy=y;
        dfs(root,nullptr,1);
        return fa1!=fa2&&lv1==lv2&&fa1!=nullptr&&lv2!=-1;
    }
};