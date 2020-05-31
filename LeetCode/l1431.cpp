class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=0;
        vector<bool> ok;
        for(auto i:candies)mx=max(mx,i);
        for(auto i:candies)ok.push_back(mx-i<=extraCandies);
        return ok;     
    }
};