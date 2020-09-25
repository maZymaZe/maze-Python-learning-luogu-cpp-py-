class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold *= k;
        int cnt = 0, len = arr.size();
        int tot = 0, l = 0, r = k;
        for (int i = 0; i < k; i++)
            tot += arr[i];
        for (; r < len; l++, r++) {
            if (tot >= threshold)
                cnt++;
            tot -= arr[l], tot += arr[r];
        }
        if (tot >= threshold)
            cnt++;
        return cnt;
    }
};