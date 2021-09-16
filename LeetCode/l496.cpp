class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int l = nums2.size();
        unordered_map<int, int> mp;
        for (int i = l - 1; i >= 0; i--) {
            while (!s.empty() && nums2[i] > s.top())
                s.pop();
            if (s.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for (auto i : nums1)
            ans.push_back(mp[i]);
        return ans;
    }
};