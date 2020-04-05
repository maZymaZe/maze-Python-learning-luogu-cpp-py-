class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    map<int,int> dict;
    RandomizedSet() {
        
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val))return false;
        nums.push_back(val);
        dict[val]=nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.count(val)==0)return false;
        dict[nums.back()]=dict[val];
        swap(nums.back(),nums[dict[val]]);
        nums.pop_back();
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r=rand()%nums.size();
        return nums[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */