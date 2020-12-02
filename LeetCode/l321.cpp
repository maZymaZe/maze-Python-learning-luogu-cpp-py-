class Solution {
   public:
    vector<int> t1, t2, bst, tmp;
    int n, m;
    void work1(vector<int>& a, int c) {
        t1.clear();
        int remain = m - c;
        for (int i = 0; i < m; i++) {
            while (!t1.empty() && a[i] > t1.back() && remain > 0) {
                t1.pop_back();
                remain--;
            }
            if (t1.size() < c) {
                t1.push_back(a[i]);
            } else
                remain--;
        }
    }
    void work2(vector<int>& a, int c) {
        t2.clear();
        int remain = n - c;
        for (int i = 0; i < n; i++) {
            while (!t2.empty() && a[i] > t2.back() && remain > 0) {
                t2.pop_back();
                remain--;
            }
            if (t2.size() < c) {
                t2.push_back(a[i]);
            } else
                remain--;
        }
    }
    vector<int> merge(vector<int>& subsequence1, vector<int>& subsequence2) {
        int x = subsequence1.size(), y = subsequence2.size();
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    bool ck() {
        int l = tmp.size();
        for (int i = 0; i < l; i++) {
            if (tmp[i] > bst[i])
                return true;
            else if (tmp[i] < bst[i])
                return false;
        }
        return false;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        m = nums1.size(), n = nums2.size();
        bst.resize(k);
        for (int i = 0; i <= m; i++) {
            if (k - i >= 0 && k - i <= n) {
                work1(nums1, i);
                work2(nums2, k - i);
                tmp = merge(t1, t2);
                if (ck()) {
                    for (int j = 0; j < k; j++)
                        bst[j] = tmp[j];
                }
            }
        }
        return bst;
    }
    int compare(vector<int>& subsequence1,
                int index1,
                vector<int>& subsequence2,
                int index2) {
        int x = subsequence1.size(), y = subsequence2.size();
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
};