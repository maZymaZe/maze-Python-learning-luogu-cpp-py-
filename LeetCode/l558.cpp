
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
   public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        // 至少一个是叶子节点
        if (quadTree1->isLeaf) {
            return quadTree1->val ? quadTree1 : quadTree2;
        } else if (quadTree2->isLeaf) {
            return quadTree2->val ? quadTree2 : quadTree1;
        }

        // 都不是叶子节点，则四个位置去递归
        quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        quadTree1->topRight =
            intersect(quadTree1->topRight, quadTree2->topRight);
        quadTree1->bottomLeft =
            intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        quadTree1->bottomRight =
            intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        // 判断是否可以合并，需要都是叶子节点，而且val相等
        if (quadTree1->topLeft->isLeaf && quadTree1->topRight->isLeaf &&
            quadTree1->bottomLeft->isLeaf && quadTree1->bottomRight->isLeaf &&
            quadTree1->topLeft->val == quadTree1->topRight->val &&
            quadTree1->topRight->val == quadTree1->bottomLeft->val &&
            quadTree1->bottomLeft->val == quadTree1->bottomRight->val) {
            quadTree1->isLeaf = true;
            quadTree1->val = quadTree1->topLeft->val;
            quadTree1->topLeft = nullptr;
            quadTree1->topRight = nullptr;
            quadTree1->bottomLeft = nullptr;
            quadTree1->bottomRight = nullptr;
        }

        return quadTree1;
    }
};
