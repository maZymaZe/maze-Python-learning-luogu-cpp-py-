#include <cstdio>
#include <cstdlib>
struct TreapNode {
    TreapNode *Left, *Right;
    int Val, Fix, Cnt, Size;
    inline int LeftSize() { return Left ? Left->Size : 0; }
    inline int RightSize() { return Right ? Right->Size : 0; }
    inline void PushUp() { Size = LeftSize() + RightSize() + Cnt; }
};

void TreapLeftRotate(TreapNode*& Root) {
    TreapNode* NewRoot = Root->Right;
    Root->Right = NewRoot->Left;
    NewRoot->Left = Root;
    Root = NewRoot;

    NewRoot = Root->Left;
    NewRoot->PushUp();
    Root->PushUp();
}
void TreapRightRotate(TreapNode*& Root) {
    TreapNode* NewRoot = Root->Left;
    Root->Left = NewRoot->Right;
    NewRoot->Right = Root;
    Root = NewRoot;

    NewRoot = Root->Right;
    NewRoot->PushUp();
    Root->PushUp();
}
TreapNode* Search(TreapNode*& Root, const int Val) {
    if (Root == NULL || Root->Val == Val)
        return Root;
    else if (Root->Val > Val)
        return Search(Root->Left, Val);
    return Search(Root->Right, Val);
}
void TreapPrint(TreapNode*& Root) {
    if (Root) {
        TreapPrint(Root->Left);
        printf("%d ", Root->Val);
        TreapPrint(Root->Right);
    }
}
void TreapInsert(TreapNode*& Root, const int& Val) {
    if (Root == NULL) {
        Root = new TreapNode();
        Root->Val = Val;
        Root->Fix = rand();
        Root->Size = 1;
        Root->Cnt = 1;
        return;
    }
    Root->Size++;
    if (Root->Val == Val) {
        Root->Cnt++;
        Root->PushUp();
    } else if (Val < Root->Val) {
        TreapInsert(Root->Left, Val);
        if (Root->Left->Fix < Root->Fix)
            TreapRightRotate(Root);
    } else {
        TreapInsert(Root->Right, Val);
        if (Root->Right->Fix < Root->Fix)
            TreapLeftRotate(Root);
    }
    Root->PushUp();
}
void TreapDelete(TreapNode*& Root, const int& Val) {
    if (Root) {
        if (Val == Root->Val) {
            if (Root->Cnt > 1) {
                (Root->Cnt)--;
            } else if (Root->Left == NULL || Root->Right == NULL) {
                TreapNode* DeletingNode = Root;
                if (!Root->Right) {
                    Root = Root->Left;
                } else {
                    Root = Root->Right;
                }
                delete DeletingNode;
            } else {
                if ((!Root->Left) || Root->Right->Fix > Root->Left->Fix) {
                    TreapRightRotate(Root);
                    TreapDelete(Root->Right, Val);
                } else {
                    TreapLeftRotate(Root);
                    TreapDelete(Root->Left, Val);
                }
            }
        } else if (Val < Root->Val) {
            TreapDelete(Root->Left, Val);
        } else {
            TreapDelete(Root->Right, Val);
        }
        if (Root)
            Root->PushUp();
    }
}
int TreapMax(TreapNode* Root) {
    if (Root) {
        while (Root->Right) {
            Root = Root->Right;
        }
        return Root->Val;
    }
    printf("ERROR:EMPTY　TREAP\n");
    return -1;
}
int TreapMin(TreapNode* Root) {
    if (Root) {
        while (Root->Left) {
            Root = Root->Left;
        }
        return Root->Val;
    }
    printf("ERROR:EMPTY　TREAP\n");
    return -1;
}
TreapNode* TreapPrev(TreapNode* Root, const int& UpperBound, TreapNode* Ans) {
    while (Root) {
        if (Root->Val < UpperBound) {
            Ans = Root;
            Root = Root->Right;
        } else
            Root = Root->Left;
    }
    return Ans;
}
TreapNode* TreapSucc(TreapNode* Root, const int& LowerBound, TreapNode* Ans) {
    while (Root) {
        if (Root->Val > LowerBound) {
            Ans = Root;
            Root = Root->Left;
        } else
            Root = Root->Right;
    }
    return Ans;
}
TreapNode* TreapNth(TreapNode*& Root, const int& N) {
    if (N <= Root->LeftSize())
        return TreapNth(Root->Left, N);
    else if (N > Root->LeftSize() + Root->Cnt)
        return TreapNth(Root->Right, N - Root->Cnt - Root->LeftSize());
    return Root;
}
int TreapRank(TreapNode*& Root, int Val) {
    if (!Root)
        return 0;
    if (Val == Root->Val) {
        return Root->LeftSize() + 1;
    } else if (Val < Root->Val)
        return TreapRank(Root->Left, Val);
    return TreapRank(Root->Right, Val) + Root->LeftSize() + Root->Cnt;
}
void TreapCleanUp(TreapNode*& Root) {
    if (Root->Left)
        TreapCleanUp(Root->Left);
    if (Root->Right)
        TreapCleanUp(Root->Right);
    if (Root)
        delete Root;
}
int main() {
    int n, t, x;
    srand(636);
    TreapNode* Root = NULL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            TreapInsert(Root, x);
        } else if (t == 2) {
            TreapDelete(Root, x);
        } else if (t == 3) {
            printf("%d\n", TreapRank(Root, x));
        } else if (t == 4) {
            printf("%d\n", TreapNth(Root, x)->Val);
        } else if (t == 5) {
            printf("%d\n", TreapPrev(Root, x, Root)->Val);
        } else if (t == 6) {
            printf("%d\n", TreapSucc(Root, x, Root)->Val);
        }
    }
    TreapCleanUp(Root);
    return 0;
}