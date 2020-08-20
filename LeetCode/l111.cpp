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
    int mi;
    void dfs(TreeNode* p,int d){
        if(!p)return;
        if(!p->left&&!p->right&&d<mi)mi=d;
        if(d<mi)dfs(p->left,d+1),dfs(p->right,d+1);
    }
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        mi=0x3f3f3f3f;
        dfs(root,1);
        return mi;
    }
};