class FrequencyTracker {
   public:
    unordered_map<int, int> mp;
    vector<int> fc;
    FrequencyTracker() {}

    void add(int number) {
        int x = mp[number];
        if (fc.size() <= x + 1)
            fc.resize(x + 2);
        fc[x + 1]++;
        fc[x]--;
        mp[number] = x + 1;
    }

    void deleteOne(int number) {
        int x = mp[number];
        if (x == 0)
            return;
        fc[x]--;
        fc[x - 1]++;
        mp[number] = x - 1;
    }

    bool hasFrequency(int frequency) {
        if (frequency >= fc.size())
            return false;
        return fc[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
