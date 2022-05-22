class Solution {
   public:
    int findLatestStep(vector<int>& arr, int m) {
        int l = arr.size(), cm = 0, ans = -1;
        vector<int> fg(l + 2, -1);
        for (int i = 0; i < l; i++) {
            int t = 1;
            if (fg[arr[i] - 1] == -1 && fg[arr[i] + 1] == -1) {
                fg[arr[i]] = 1;
                if (1 == m)
                    cm++;
            } else if (fg[arr[i] - 1] == -1) {
                if (fg[arr[i] + 1] == m)
                    cm--;
                fg[arr[i]] = fg[arr[i] + 1] + 1;
                fg[arr[i] + fg[arr[i] + 1]] = fg[arr[i]];
                if (fg[arr[i]] == m)
                    cm++;
            } else if (fg[arr[i] + 1] == -1) {
                if (fg[arr[i] - 1] == m)
                    cm--;
                fg[arr[i]] = fg[arr[i] - 1] + 1;
                fg[arr[i] - fg[arr[i] - 1]] = fg[arr[i]];
                if (fg[arr[i]] == m)
                    cm++;
            } else {
                if (fg[arr[i] - 1] == m)
                    cm--;
                if (fg[arr[i] + 1] == m)
                    cm--;
                int tot = fg[arr[i] + 1] + fg[arr[i] - 1] + 1;
                fg[arr[i] - fg[arr[i] - 1]] = fg[arr[i] + fg[arr[i] + 1]] = tot;
                if (tot == m)
                    cm++;
            }
            if (cm > 0)
                ans = i + 1;
        }
        return ans;
    }
};