class Solution {
public:
    unordered_set<int> s;
    bool containsDuplicate(vector<int>& nums) {
        for(int a:nums){
            if(s.count(a))return true;
            s.insert(a);
        }
        return false;
    }
};