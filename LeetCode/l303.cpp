class NumArray {
public:
    vector<int> ps;
    NumArray(vector<int>& nums) {
        int p=0;
        ps.push_back(0);
        for(int i:nums)p+=i,ps.push_back(p);
    }
    
    int sumRange(int i, int j) {
        return ps[j+1]-ps[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */