class Solution {
   public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int l = dist.size();
        for (int i = 0; i < l; i++) {
            dist[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(dist.begin(), dist.end());
        int ans = 0;
        for (int i = 0; i < l; i++) {
            if (i < dist[i])
                ans++;
            else
                break;
        }
        return ans;
    }
};