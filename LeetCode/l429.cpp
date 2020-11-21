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
struct pr{
    Node* n;
    int d;
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<pr> q;
        q.push({root,0});
        while(!q.empty()) {
            pr t=q.top();q.pop();
            if(ans.size()>t.d){
                ans[t.d].push_back(t.n->val);
            }else{
                ans.push_back(vector<int>());
                ans[t.d].push_back(t.n->val);
            }
            for(auto &x:t.n->children){
                q.push({x,t.d+1});
            }
        }
        return ans;
    }
};