class Solution {
   public:
    int getWinner(vector<int>& arr, int k) {
        int wc = 0;
        deque<int> dq(arr.begin(), arr.end());
        int l = arr.size();
        for (int i = 0; i < 3 * l; i++) {
            int t0 = dq[0], t1 = dq[1];
            if (t0 > t1) {
                wc++;
                dq.pop_front();
                dq.pop_front();
                dq.push_front(t0);
                dq.push_back(t1);
            } else {
                wc = 1;
                dq.pop_front();
                dq.push_back(t0);
            }
            if (wc >= k) {
                return dq[0];
            }
        }
        return dq[0];
    }
};