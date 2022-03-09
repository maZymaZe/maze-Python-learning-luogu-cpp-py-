class Solution {
   public:
    int bestRotation(vector<int>& A) {
        int l = A.size(), cnt = 0, ans = -1, p = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < l; i++) {
            if (A[i] <= i) {
                cnt++;
                q.push(i - A[i]);
            }
        }
        ans = max(cnt, ans);
        for (int i = 0; i < l - 1; i++) {
            cnt++;
            q.push(i + l - A[i]);
            while (!q.empty() && i >= q.top()) {
                q.pop();
                cnt--;
            }
            if (cnt > ans) {
                ans = cnt;
                p = i + 1;
            }
        }
        return p;
    }
};