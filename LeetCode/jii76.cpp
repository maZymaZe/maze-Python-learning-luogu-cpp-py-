int ans;
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        qsort(0, nums.size() - 1, nums, nums.size() - k);
        return ans;
    }
    void qsort(int l, int r, vector<int>& a, int m) {
        int mid = a[(l + r) / 2], i = l, j = r;
        do {
            while (a[j] > mid)
                j--;
            while (a[i] < mid)
                i++;
            if (i <= j)
                swap(a[i], a[j]), i++, j--;
        } while (i <= j);
        if (m <= j)
            qsort(l, j, a, m);
        else if (m >= i)
            qsort(i, r, a, m);
        else {
            ans = a[j + 1];
        }
    }
};