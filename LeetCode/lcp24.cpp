class Solution {
   public:
    static const int MOD = 1e9 + 7;
    struct ddd {
        priority_queue<int> mah;
        priority_queue<int, vector<int>, greater<int>> mih;
        long long toti = 0, totm = 0;
        void insert(int x) {
            mih.push(x);
            toti += x;
            if (mih.size() > mah.size()) {
                int t = mih.top();
                toti -= t;
                mih.pop();
                mah.push(t);
                totm += t;
            } else {
                if (mih.top() < mah.top()) {
                    int a = mih.top(), b = mah.top();
                    mih.pop(), mah.pop();
                    mih.push(b), mah.push(a);
                    toti += b - a;
                    totm += a - b;
                }
            }
        }
        int cal() {
            int x = mah.top();
            return ((long long)x * mah.size() - totm + toti -
                    (long long)x * mih.size()) %
                   MOD;
        }
    };
    vector<int> numsGame(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            nums[i] -= i;
        ddd d;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            d.insert(nums[i]);
            ans.push_back(d.cal());
        }
        return ans;
    }
};