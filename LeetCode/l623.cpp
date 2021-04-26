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
    void dfs(TreeNode * root,int val,int depth,int d){
        if(!root)return;
        if(d==depth-1){
            TreeNode* nn=new TreeNode(val,root->left,nullptr);
            root->left=nn;
            TreeNode* nn2=new TreeNode(val,nullptr,root->right);
            root->right=nn2;
        }else{
            dfs(root->left,val,depth,d+1);
            dfs(root->right,val,depth,d+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* nh=new TreeNode(val,root,nullptr);
            return nh;
        }
        dfs(root,val,depth,1);
        return root;
    }
};