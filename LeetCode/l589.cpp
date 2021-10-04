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
    vector<int> ans;
    void dfs(Node* root) {
        if (!root)
            return;
        ans.push_back(root->val);
        for (auto p : root->children)
            dfs(p);
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
};