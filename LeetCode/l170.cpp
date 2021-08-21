class TwoSum {
   public:
    /** Initialize your data structure here. */
    map<int, int> mp;
    TwoSum() { mp.clear(); }

    /** Add the number to an internal data structure.. */
    void add(int number) { mp[number]++; }

    /** Find if there exists any pair of numbers which sum is equal to the
     * value. */
    bool find(int value) {
        for (auto i : mp) {
            if (2ll * i.first < value) {
                if (mp.count(value - i.first)) {
                    return true;
                }
            } else if (2ll * i.first == value) {
                if (mp[i.first] > 1)
                    return true;
            } else if (2ll * i.first > value)
                break;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */