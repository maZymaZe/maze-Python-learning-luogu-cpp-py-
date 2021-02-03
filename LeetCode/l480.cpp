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

TreapNode* TreapNth(TreapNode*& Root, const int& N) {
    if (N <= Root->LeftSize())
        return TreapNth(Root->Left, N);
    else if (N > Root->LeftSize() + Root->Cnt)
        return TreapNth(Root->Right, N - Root->Cnt - Root->LeftSize());
    return Root;
}
void TreapCleanUp(TreapNode*& Root) {
    if (Root->Left)
        TreapCleanUp(Root->Left);
    if (Root->Right)
        TreapCleanUp(Root->Right);
    if (Root)
        delete Root;
}
class Solution {
   public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        srand(636);
        TreapNode* Root = NULL;
        vector<double> ans;
        int l = nums.size(), f = k % 2, t = k / 2 + 1;

        for (int i = 0; i < k; i++)
            TreapInsert(Root, nums[i]);
        if (f) {
            ans.push_back((double)TreapNth(Root, t)->Val);
        } else {
            ans.push_back(
                (double)((long long)TreapNth(Root, t)->Val + TreapNth(Root, t - 1)->Val) /
                2);
        }
        for (int i = k; i < l; i++) {
            TreapInsert(Root, nums[i]);
            TreapDelete(Root, nums[i - k]);
            if (f) {
                ans.push_back((double)TreapNth(Root, t)->Val);
            } else {
                ans.push_back((double)((long long)TreapNth(Root, t)->Val +
                                       TreapNth(Root, t - 1)->Val) /
                              2);
            }
        }
        TreapCleanUp(Root);
        return ans;
    }
};