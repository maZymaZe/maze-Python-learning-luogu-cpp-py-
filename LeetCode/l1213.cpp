class Solution {
   public:
    vector<int> arraysIntersection(vector<int>& arr1,
                                   vector<int>& arr2,
                                   vector<int>& arr3) {
        int l1 = arr1.size(), l2 = arr2.size(), l3 = arr3.size(), p1 = 0,
            p2 = 0, p3 = 0;
        vector<int> ans;
        while (p1 < l1 && p2 < l2 && p3 < l3) {
            if (arr1[p1] == arr2[p2] && arr1[p1] == arr3[p3]) {
                ans.push_back(arr1[p1]);
                p1++, p2++, p3++;
            } else if (arr1[p1] <= min(arr2[p2], arr3[p3])) {
                p1++;
            } else if (arr2[p2] <= min(arr1[p1], arr3[p3])) {
                p2++;
            } else if (arr3[p3] <= min(arr1[p1], arr2[p2])) {
                p3++;
            }
        }
        return ans;
    }
};