class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        arr.resize(k);
        return arr;
    }
};