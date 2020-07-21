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
vector<TreeNode*> f(int l,int r){
    if(l>r)return {nullptr};
    if(l==r){
        TreeNode* root=new TreeNode(l);
        return {root};
    }
    vector<TreeNode*> ans;
    for(int i=l;i<=r;i++){
        vector<TreeNode*> t1=f(l,i-1),t2=f(i+1,r);
        for(int j=0;j<t1.size();j++){
            for(int k=0;k<t2.size();k++){
                TreeNode* root=new TreeNode(i,t1[j],t2[k]);
                ans.push_back(root);
            }
        } 
    }
    return ans;

}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {};
        return f(1,n);
    }
};