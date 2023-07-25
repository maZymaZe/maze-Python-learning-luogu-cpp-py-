class Solution {
   public:
    int halveArray(vector<int>& nums) {
        double tot = 0;
        priority_queue<double> pq;
        for (int i : nums) {
            pq.push(i);
            tot += i;
        }
        double x = tot;
        int ans = 0;
        while (x * 2 > tot) {
            double t = pq.top();
            x -= t / 2;
            pq.pop();
            pq.push(t / 2);
            ans++;
        }
        return ans;
    }
};