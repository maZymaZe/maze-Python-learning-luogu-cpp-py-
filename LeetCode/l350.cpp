class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i:nums1){
            if(mp.count(i))mp[i]++;
            else mp.insert({i,1});
        }
        vector<int> ans;
        for(int i:nums2){
            if(mp.count(i)){
                if(mp[i]==1){
                    mp.erase(i);
                }
                else mp[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};