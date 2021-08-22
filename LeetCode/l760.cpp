class Solution {
   public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int> > mp;
        int l = nums2.size();
        for (int i = 0; i < l; i++) {
            mp[nums2[i]].push_back(i);
        }
        vector<int> answer(l);
        for (int i = 0; i < l; i++) {
            answer[i] = mp[nums1[i]].back();
            mp[nums1[i]].pop_back();
        }
        return answer;
    }
};