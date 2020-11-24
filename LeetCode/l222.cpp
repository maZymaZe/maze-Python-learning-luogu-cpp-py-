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
    int h=0,p,stk[40];
    bool ck(int x,TreeNode * root){
        p=0;x--;
        for(int i=1;i<=h;i++){
            stk[i]=x&1;
            x>>=1;
        }

        for(int i=h;i>=1; i--){
            if(stk[i]==0){
                if(root->left){
                    root=root->left;
                }else return false;
            }else{
                if(root->right){
                    root=root->right;
                }else return false;
            }
        }
        return true;

        
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        auto u=root;
        while(u->left)u=u->left,h++;
        int l=1,r=1<<h;
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(ck(mid,root)){
                l=mid;
            }else r=mid-1;
        }
        return l+(1<<h)-1;
    }
};