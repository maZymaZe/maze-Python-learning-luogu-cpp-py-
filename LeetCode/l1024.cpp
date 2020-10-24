struct cmp {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};
class Solution {
   public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        int pot = 1, ans = 0, ml, poc = 0, l = clips.size();
        while (poc < l) {
            ml = -1;
            while (poc < l && clips[poc][0] <= pot) {
                if (clips[poc][1] > ml)
                    ml = clips[poc][1];
                poc++;
            }
            if (ml == -1)
                return -1;
            ans++;
            if (ml >= T)
                return ans;
            pot = ml + 1;
        }
        return -1;
    }
};