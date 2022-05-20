class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = arr.size();
        for (int i = 0; i < l; i++) {
            arr[i] -= (i + 1);
        }
        auto it = lower_bound(arr.begin(), arr.end(), k);
        if (it == arr.begin())
            return k;
        --it;
        return (it - arr.begin() + 1) + k;
    }
};