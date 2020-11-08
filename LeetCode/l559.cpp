/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int md=0;
    void dfs(Node* root,int d){
        if(!root)return;
        md=max(md,d);
        for(auto i:root->children){
            dfs(i,d+1);
        }
    }
    int maxDepth(Node* root) {
        if(!root)return 0;
        dfs(root,1);
        return md;
    }
};