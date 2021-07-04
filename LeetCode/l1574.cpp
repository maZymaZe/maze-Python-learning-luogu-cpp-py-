class Solution {
   public:
    int fl(vector<int>& arr, int s, int e, int t) {
        while (s <= e) {
            int m = (s + e) / 2;
            if (arr[m] < t)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return 0;

        int le = 0;
        while (le < n - 1) {
            if (arr[le] > arr[le + 1])
                break;
            ++le;
        }
        if(le==n-1)return 0;
        int re = n - 1;
        while (re > 0) {
            if (arr[re] < arr[re - 1])
                break;
            --re;
        }
        
        if (arr[le] <= arr[re])
            return re - le - 1;
        int res = min(n - le - 1, re);
        for (int i = 0; i <= le; i++) {
            if (re - i - 1 < res) {
                int j = fl(arr, re, n - 1, arr[i]);
                res = min(res, j - i - 1);
            }
        }
        return res;
    }
};