/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* create(Node* root) {
        if(!root)return nullptr;
        if(mp.count(root))return mp[root];
        Node* ret=new Node(root->val);
        mp.insert({root,ret});
        ret->next = create(root->next);
        ret->random = create(root->random);
        
        return ret;
    }
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        return create(head);
    }
};