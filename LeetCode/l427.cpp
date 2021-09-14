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
    Node* dfs(int rs, int cs, int re, int ce, vector<vector<int>>& grid) {
        if (rs == re && cs == ce) {
            return new Node(grid[rs][cs], 1);
        }
        Node* tl = dfs(rs, cs, rs + (re - rs) / 2, cs + (ce - cs) / 2, grid);
        Node* tr =
            dfs(rs, cs + (ce - cs) / 2 + 1, rs + (re - rs) / 2, ce, grid);
        Node* bl =
            dfs(rs + (re - rs) / 2 + 1, cs, re, cs + (ce - cs) / 2, grid);
        Node* br =
            dfs(rs + (re - rs) / 2 + 1, cs + (ce - cs) / 2 + 1, re, ce, grid);
        if (tl->val == tr->val && tl->val == bl->val && tl->val == br->val &&
            tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            return tl;
        }
        return new Node(1, 0, tl, tr, bl, br);
    }
    Node* construct(vector<vector<int>>& grid) {
        return dfs(0, 0, grid.size() - 1, grid.size() - 1, grid);
    }
};