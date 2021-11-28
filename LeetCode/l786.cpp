struct fc {
    int a, b;
    bool operator<(const fc& x) const { return a * x.b < x.a * b; }
};
class Solution {
   public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int l = arr.size();
        vector<fc> v;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                v.push_back({arr[i], arr[j]});
            }
        }
        nth_element(v.begin(), v.begin() + k - 1, v.end());
        return {v[k - 1].a, v[k - 1].b};
    }
};