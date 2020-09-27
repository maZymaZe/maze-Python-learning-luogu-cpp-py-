/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void handle(Node*&l,Node*&p,Node*&n){
        if(l)l->next=p;
        if(!n)n=p;
        l=p;
    }
    Node* connect(Node* root) {
        if(!root)return root;
        Node* s=root;
        while(s){
            Node *l=0,*n=0;
            for(Node*p=s;p;p=p->next){
                if(p->left)handle(l,p->left,n);
                if(p->right)handle(l,p->right,n);
            }
            s=n;
        }
        return root;
    }
};