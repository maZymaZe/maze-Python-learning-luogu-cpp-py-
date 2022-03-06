class Solution {
   public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int l = security.size();
        vector<int> u(l), d(l), ans;
        time++;
        d[0] = u[l - 1] = 1;
        for (int i = 1; i < l; i++) {
            if (security[i] <= security[i - 1])
                d[i] = d[i - 1] + 1;
            else
                d[i] = 1;
        }
        for (int i = l - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1])
                u[i] = u[i + 1] + 1;
            else
                u[i] = 1;
        }
        for (int i = 0; i < l; i++)
            if (u[i] >= time && d[i] >= time)
                ans.push_back(i);
        return ans;
    }
};