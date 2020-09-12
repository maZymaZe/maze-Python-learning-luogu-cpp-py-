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
    int cnt[10002]={0};
    long long sum[10002]= {0};
    vector<double> ans;
    void dfs(int deep,TreeNode* root){
        if(!root)return;
        cnt[deep]++;
        sum[deep]+=root->val;
        dfs(deep+1,root->left);
        dfs(deep+1,root->right);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(0, root);
        int p=0;
        while(cnt[p])ans.emplace_back((double)sum[p]/cnt[p]),p++;
        return ans;
    }
};