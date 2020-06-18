/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct st{
    int f,v,o,c;
};
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        if(S.size()==0)return NULL;
        int p=0;
        while(p<S.size()&&S[p]!='-')p++;
        TreeNode *root=new TreeNode(stoi(S.substr(0,p)));
        root=sc(p,S.size(),1,S,root);
        return root;
    }
    st scan(int l,int r,int n,string &S){
        int ff;
        for(int i=l;i<r;i++){
            ff=1;
            if(S[i-1]!='-'){
                if(i+n>=r||S[i+n]=='-')ff=0;
                else for(int j=1;j<=n;j++){
                    if(i+j-1>=r){
                        ff=0;break;
                    }
                    if(S[i+j-1]!='-'){
                        ff=0;break;
                    }
                }
            }
            else ff=0;
            if(ff==1){
                int p=i+n;
                while(p<r&&S[p]!='-')p++;
                return {1,stoi(S.substr(i+n,p-i-n)),p,i};
            }
        }
        return {0,0,0,0};
    }
    TreeNode* sc(int l,int r,int n,string &S,TreeNode* fa){
        TreeNode* p1,*p2;
        st t1=scan(l,r,n,S);
        if(t1.f==1){
            st t2=scan(t1.o,r,n,S);
            if(t2.f==1){
                p1=new TreeNode(t1.v);
                p2=new TreeNode(t2.v);
                p1=sc(t1.o,t2.c,n+1,S,p1);
                p2=sc(t2.o,r,n+1,S,p2);
            }
            else{
                p2=NULL;
                p1=new TreeNode(t1.v);
                p1=sc(t1.o,r,n+1,S,p1);
            }
        }
        else{
            p1=NULL;
            p2=NULL;
        }
        fa->left=p1;
        fa->right=p2;
        return fa;
    }
};