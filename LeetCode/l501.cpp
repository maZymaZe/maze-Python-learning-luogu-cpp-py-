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
    int base=0,cnt=0,mcnt=0;
    vector<int> ans;
    void update(int x){
        if(x==base)++cnt;
        else cnt=1,base=x;
        if(cnt==mcnt)ans.push_back(base);
        if(cnt>mcnt)mcnt=cnt,ans.clear(),ans.push_back(base);
    }
    vector<int> findMode(TreeNode* root) {
        TreeNode *cur=root,*pre=nullptr;
        while(cur){
            if(!cur->left){
                update(cur->val);
                cur=cur->right;
                continue;
            }
            pre=cur->left;
            while(pre->right&&pre->right!=cur){
                pre=pre->right;
            }
            if(!pre->right){
                pre->right=cur;
                cur=cur->left;
            }else{
                pre->right=nullptr;
                update(cur->val);
                cur=cur->right;
            }
        }
        return ans;

    }
};