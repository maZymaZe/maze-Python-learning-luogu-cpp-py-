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
    char res[205];
    vector<string> ans;
    int stk[13],tp;
    void dfs(TreeNode* root,int p){
        if(!root)return;
        int tmp=root->val;
        tp=0;
        if(tmp<0)tmp=-tmp,res[p++]='-';
        while(tmp)stk[++tp]=tmp%10,tmp/=10;
        if(tp==1)res[p++]=stk[1]+'0';
        else{
            for(int i=tp;i>0;i--)res[p++]=stk[i]+'0';
        }
        if(!root->left&&!root->right){
            res[p]='\0';
            ans.push_back(string(res));
            return;
        }
        res[p++]='-',res[p++]='>';
        if(root->left)dfs(root->left,p);
        if(root->right)dfs(root->right,p);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};