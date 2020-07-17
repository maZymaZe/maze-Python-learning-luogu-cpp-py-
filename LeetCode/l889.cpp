/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int l;
TreeNode* f(vector<int>& pre, vector<int>& post,int l1,int r1,int l2,int r2){
    if(l1>r1) return NULL;
    TreeNode* root=new TreeNode(pre[l1]);
    if(l1==r1)return root;
    for(int i=l2;i<=r2-1;i++){
        if(post[i]==pre[l1+1]){
            root->left=f(pre,post,l1+1,i-l2+l1+1,l2,i);
            root->right=f(pre,post,i-l2+l1+2,r1,i+1,r2-1);
            break;
        }

    }
    return root;
}  
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        l=pre.size();
        return f(pre,post,0,l-1,0,l-1);
    }
};