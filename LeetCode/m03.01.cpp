class TripleInOne {
   public:
    vector<int> v;
    int tp[3], sz;
    TripleInOne(int stackSize) {
        sz = stackSize;
        v.resize(stackSize * 3);
        tp[0] = 0, tp[1] = stackSize, tp[2] = stackSize * 2;
    }

    void push(int stackNum, int value) {
        if (tp[stackNum] != (stackNum + 1) * sz) {
            v[tp[stackNum]++] = value;
        }
    }

    int pop(int stackNum) {
        if (tp[stackNum] != stackNum * sz) {
            return v[--tp[stackNum]];
        }
        return -1;
    }

    int peek(int stackNum) {
        if (tp[stackNum] != stackNum * sz) {
            return v[tp[stackNum] - 1];
        }
        return -1;
    }

    bool isEmpty(int stackNum) { return stackNum * sz == tp[stackNum]; }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */