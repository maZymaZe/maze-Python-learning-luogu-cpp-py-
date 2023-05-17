class Solution {
   public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        int l1 = arr1.size(), l2 = arr2.size();
        int c = 0, p1 = l1 - 1, p2 = l2 - 1;
        while (p1 >= 0 && p2 >= 0) {
            int x = c + arr1[p1] + arr2[p2];
            if (x > 1) {
                x -= 2;
                c = -1;
            } else if (x < 0) {
                x += 2;
                c = 1;
            } else {
                c = 0;
            }
            ans.push_back(x);
            p1--, p2--;
        }
        while (p1 >= 0) {
            int x = c + arr1[p1];
            if (x > 1) {
                x -= 2;
                c = -1;
            } else if (x < 0) {
                x += 2;
                c = 1;
            } else {
                c = 0;
            }
            ans.push_back(x);
            p1--;
        }
        while (p2 >= 0) {
            int x = c + arr2[p2];
            if (x > 1) {
                x -= 2;
                c = -1;
            } else if (x < 0) {
                x += 2;
                c = 1;
            } else {
                c = 0;
            }
            ans.push_back(x);
            p2--;
        }
        if (c == 1) {
            ans.push_back(1);
        } else if (c == -1) {
            ans.push_back(1);
            ans.push_back(1);
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};