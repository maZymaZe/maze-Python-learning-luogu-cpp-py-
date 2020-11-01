class Solution {
public:
    unordered_set<int> s;
    vector<int> ans;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for(int i:nums1)s.insert(i);
        for(int i:nums2){
            if(s.count(i)){
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};