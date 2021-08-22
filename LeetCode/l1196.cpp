class Solution {
   public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0, u = 5000;
        for (int x : arr) {
            if (u >= x) {
                ans++;
                u -= x;
            } else
                break;
        }
        return ans;
    }
};