class Solution {
   public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v[2], op[2];
        sort(arr2.begin(), arr2.end());
        if (arr2[0] < arr1[0]) {
            v[0].push_back(arr2[0]), op[0].push_back(1);
        }
        v[0].push_back(arr1[0]), op[0].push_back(0);
        int l = arr1.size();
        for (int i = 1; i < l; i++) {
            int old = ((i - 1) & 1), nw = (i & 1);
            int vl = v[old].size();
            int uflag = (!v[old].empty() && v[old][0] < arr1[i]);
            int mop = l;
            for (int j = 0; j < vl; j++) {
                if (v[old][j] < arr1[i])
                    mop = min(mop, op[old][j]);
                auto it = upper_bound(arr2.begin(), arr2.end(), v[old][j]);
                if (it == arr2.end()) {
                    continue;
                } else {
                    if ((*it) < arr1[i] &&
                        (op[nw].empty() || op[old][j] + 1 < op[nw].back())) {
                        v[nw].push_back(*it), op[nw].push_back(op[old][j] + 1);
                    } else {
                        if (uflag) {
                            v[nw].push_back(arr1[i]), op[nw].push_back(mop);
                            uflag = 0;
                        }
                        if ((*it) > arr1[i] &&
                            (op[nw].empty() ||
                             op[old][j] + 1 < op[nw].back())) {
                            v[nw].push_back(*it);
                            op[nw].push_back(op[old][j] + 1);
                        }
                    }
                }
            }
            if (uflag && (op[nw].empty() || mop < op[nw].back())) {
                v[nw].push_back(arr1[i]), op[nw].push_back(mop);
            }
            v[old].clear();
            op[old].clear();
        }
        if (v[(l - 1) & 1].empty())
            return -1;
        return op[(l - 1) & 1].back();
    }
};