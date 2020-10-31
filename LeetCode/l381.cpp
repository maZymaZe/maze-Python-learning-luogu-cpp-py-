class RandomizedCollection {
   public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did
     * not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection
     * contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end())
            return false;
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1)
            idx[nums[i]].insert(i);
        if (idx[val].size() == 0)
            idx.erase(val);
        nums.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() { return nums[rand() % nums.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */