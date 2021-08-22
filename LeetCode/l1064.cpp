class Solution {
   public:
    int fixedPoint(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        int mid = (l + r) / 2;
        int ans = -1;
        while (l <= r) {
            mid = (l + r + 1) / 2;
            if (arr[mid] >= mid) {
                r = mid - 1;
                if (arr[mid] == mid) {
                    ans = mid;
                }
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};