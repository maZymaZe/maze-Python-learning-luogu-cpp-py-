#include <cstdio>
struct BSTNode {
    BSTNode *Left, *Right;
    int Val, Cnt, Size;
    inline int LeftSize() { return Left ? Left->Size : 0; }
    inline int RightSize() { return Right ? Right->Size : 0; }
    inline void PushUp() { Size = LeftSize() + RightSize() + Cnt; }
};

void BSTInsert(BSTNode*& Root, const int& Val) {
    if (Root == NULL) {
        Root = new BSTNode();
        Root->Val = Val;

        Root->Size = 1;
        Root->Cnt = 1;
        return;
    }
    Root->Size++;
    if (Root->Val == Val) {
        Root->Cnt++;
        Root->PushUp();
    } else if (Val < Root->Val) {
        BSTInsert(Root->Left, Val);

    } else {
        BSTInsert(Root->Right, Val);
    }
    Root->PushUp();
}
void BSTDelete(BSTNode*& Root, const int& Val) {
    if (Root) {
        if (Val == Root->Val) {
            if (Root->Cnt > 1) {
                (Root->Cnt)--;
            } else if (Root->Left == NULL || Root->Right == NULL) {
                BSTNode* DeletingNode = Root;
                if (!Root->Right) {
                    Root = Root->Left;
                } else {
                    Root = Root->Right;
                }
                delete DeletingNode;
            } else {
                BSTNode* DeletingNode = Root;
                int ExtraSize=Root->Right->Size;
                Root = Root->Left;
                BSTNode* FindBiggest = Root;
                while (FindBiggest->Right) {
                    FindBiggest->Size+=ExtraSize;
                    FindBiggest = FindBiggest->Right;
                }
                FindBiggest->Right = DeletingNode->Right;
                FindBiggest->Size+=ExtraSize;
                delete DeletingNode;
            }
        } else if (Val < Root->Val) {
            BSTDelete(Root->Left, Val);
        } else {
            BSTDelete(Root->Right, Val);
        }
        if (Root)
            Root->PushUp();
    }
}
BSTNode* BSTPrev(BSTNode* Root, const int& UpperBound, BSTNode* Ans) {
    while (Root) {
        if (Root->Val < UpperBound) {
            Ans = Root;
            Root = Root->Right;
        } else
            Root = Root->Left;
    }
    return Ans;
}
BSTNode* BSTSucc(BSTNode* Root, const int& LowerBound, BSTNode* Ans) {
    while (Root) {
        if (Root->Val > LowerBound) {
            Ans = Root;
            Root = Root->Left;
        } else
            Root = Root->Right;
    }
    return Ans;
}
BSTNode* BSTNth(BSTNode*& Root, const int& N) {
    if (N <= Root->LeftSize())
        return BSTNth(Root->Left, N);
    else if (N > Root->LeftSize() + Root->Cnt)
        return BSTNth(Root->Right, N - Root->Cnt - Root->LeftSize());
    return Root;
}
int BSTRank(BSTNode*& Root, int Val) {
    if (!Root)
        return 0;
    if (Val == Root->Val) {
        return Root->LeftSize() + 1;
    } else if (Val < Root->Val)
        return BSTRank(Root->Left, Val);
    return BSTRank(Root->Right, Val) + Root->LeftSize() + Root->Cnt;
}
void BSTCleanUp(BSTNode*& Root) {
    if (Root->Left)
        BSTCleanUp(Root->Left);
    if (Root->Right)
        BSTCleanUp(Root->Right);
    if (Root)
        delete Root;
}
int main() {
    int n, t, x;
    BSTNode* Root = NULL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            BSTInsert(Root, x);
        } else if (t == 2) {
            BSTDelete(Root, x);
        } else if (t == 3) {
            printf("%d\n", BSTRank(Root, x));
        } else if (t == 4) {
            printf("%d\n", BSTNth(Root, x)->Val);
        } else if (t == 5) {
            printf("%d\n", BSTPrev(Root, x, Root)->Val);
        } else if (t == 6) {
            printf("%d\n", BSTSucc(Root, x, Root)->Val);
        }
    }
    BSTCleanUp(Root);
    return 0;
}