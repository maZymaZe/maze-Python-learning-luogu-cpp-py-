class NumArray {
   public:
    vector<int> ta, nb;
    int l;
    void ad(int p, int v) {
        while (p < l) {
            ta[p] += v;
            p += (-p & p);
        }
    }
    int qe(int p) {
        int r = 0;
        while (p) {
            r += ta[p];
            p -= (-p & p);
        }
        return r;
    }
    NumArray(vector<int>& nums) {
        nb = nums;
        l = nums.size() * 2 + 10;
        ta.resize(l);
        for (int i = 0; i < nums.size(); i++) {
            ad(i + 1, nums[i]);
        }
    }

    void update(int index, int val) {
        int del = val - nb[index];
        ad(index + 1, del);
        nb[index] = val;
    }

    int sumRange(int left, int right) { return qe(right + 1) - qe(left); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */