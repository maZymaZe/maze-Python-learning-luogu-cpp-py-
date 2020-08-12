/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
unordered_map<Node*,Node*> mp;
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        mp.clear();
        return work(node);
    }
    Node* work(Node* node) {
        if(mp.count(node))return mp[node];
        Node* ret=new Node(node->val);
        mp.insert({node,ret});
        for(auto i:(node->neighbors)){
            ret->neighbors.push_back(work(i));
        }
        return ret;
    }
};