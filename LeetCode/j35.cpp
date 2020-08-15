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
    Node* copyRandomList(Node* head) {
        mp.clear();
        return work(head);
    }
    Node* work(Node* head){
        if(!head)return head;
        if(mp.count(head))return mp[head];
        Node* p=new Node(head->val);
        mp.insert({head,p});
        p->next=work(head->next);
        p->random=work(head->random);
        return p;
    }
};