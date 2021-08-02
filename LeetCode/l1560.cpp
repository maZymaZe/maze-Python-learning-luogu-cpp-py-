class Solution {
   public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int l = rounds.size();
        vector<int> ans;
        int p = rounds[l - 1];
        ans.push_back(p);
        while (1) {
            if (rounds[0] == p)
                break;
            p--;
            if (p == 0)
                p = n;
            ans.push_back(p);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};