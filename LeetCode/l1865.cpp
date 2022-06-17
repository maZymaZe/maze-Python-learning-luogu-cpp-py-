class FindSumPairs {
   public:
    unordered_map<int, int> m1, m2;
    vector<int> v2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i : nums1)
            m1[i]++;
        for (int i : nums2)
            m2[i]++;
        v2 = nums2;
    }

    void add(int index, int val) {
        m2[v2[index]]--;
        v2[index] += val;
        m2[v2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (auto i : m1) {
            ans += i.second * m2[tot - i.first];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */