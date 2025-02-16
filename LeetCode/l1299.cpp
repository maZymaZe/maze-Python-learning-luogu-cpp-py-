class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int l = arr.size() - 1, mx = -1, tmp;
        while (l >= 0) {
            tmp = mx;
            mx = max(mx, arr[l]);
            arr[l] = tmp;
            l--;
        }
        return arr;
    }
};