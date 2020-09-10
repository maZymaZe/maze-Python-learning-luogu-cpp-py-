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
    int cnt[10002]={0},mi,ans;
    void dfs(TreeNode* root,int deep){
        if(!root)return;
        cnt[deep]+=root->val;
        dfs(root->left,deep+1);
        dfs(root->right,deep+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        mi=cnt[1],ans=1;
        for(int i=10000;i>0;i--){
            if(cnt[i]>=mi)mi=cnt[i],ans=i;
        }
        return ans;
    }
};