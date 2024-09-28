class BookMyShow {
   private:
    int n;
    int m;
    vector<int> minTree;
    vector<long long> sumTree;

    void modify(int i, int l, int r, int index, int val) {
        if (l == r) {
            minTree[i] = val;
            sumTree[i] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid) {
            modify(i * 2, l, mid, index, val);
        } else {
            modify(i * 2 + 1, mid + 1, r, index, val);
        }
        minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
        sumTree[i] = sumTree[i * 2] + sumTree[i * 2 + 1];
    }

    int queryMinRow(int i, int l, int r, int val) {
        if (l == r) {
            if (minTree[i] > val) {
                return n;
            }
            return l;
        }
        int mid = (l + r) / 2;
        if (minTree[i * 2] <= val) {
            return queryMinRow(i * 2, l, mid, val);
        } else {
            return queryMinRow(i * 2 + 1, mid + 1, r, val);
        }
    }

    long long querySum(int i, int l, int r, int l2, int r2) {
        if (l2 <= l && r <= r2) {
            return sumTree[i];
        }
        int mid = (l + r) / 2;
        long long sum = 0;
        if (mid >= l2) {
            sum += querySum(i * 2, l, mid, l2, r2);
        }
        if (mid + 1 <= r2) {
            sum += querySum(i * 2 + 1, mid + 1, r, l2, r2);
        }
        return sum;
    }

   public:
    BookMyShow(int n, int m) : n(n), m(m), minTree(4 * n), sumTree(4 * n) {}

    vector<int> gather(int k, int maxRow) {
        int i = queryMinRow(1, 0, n - 1, m - k);
        if (i > maxRow) {
            return {};
        }
        int used = querySum(1, 0, n - 1, i, i);
        modify(1, 0, n - 1, i, used + k);
        return {i, used};
    }

    bool scatter(int k, int maxRow) {
        long long usedTotal = querySum(1, 0, n - 1, 0, maxRow);
        if ((long long)(maxRow + 1) * m - usedTotal < k) {
            return false;
        }
        int i = queryMinRow(1, 0, n - 1, m - 1);
        while (true) {
            long long used = querySum(1, 0, n - 1, i, i);
            if (m - used >= k) {
                modify(1, 0, n - 1, i, used + k);
                break;
            }
            k -= m - used;
            modify(1, 0, n - 1, i, m);
            i++;
        }
        return true;
    }
};