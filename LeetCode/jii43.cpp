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
class CBTInserter {
public:
    int cnt;
    TreeNode* ROOT;
    CBTInserter(TreeNode* root) {
        cnt=0;
        dfs(root);
        ROOT=root;
    }
    void dfs(TreeNode* root){
        if(!root)return;
        cnt++;
        dfs(root->left);
        dfs(root->right);
    }
    
    int insert(int v) {
        cnt++;
        vector<int> t;
        int tt=cnt;
        while(tt!=1){
            t.push_back(tt&1);
            tt>>=1;
        }
        int l=t.size();
        TreeNode* p=ROOT;
        for(int i=l-1; i>0;i--){
            if(t[i])p=p->right;
            else p=p->left;
        }
        int ret=p->val;
        TreeNode* np=new TreeNode(v);
        if(t[0])p->right=np;
        else p->left=np;
        return ret;
    }
    
    TreeNode* get_root() {
        return ROOT;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */