class Solution {
   public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        int l1 = list1.size(), l2 = list2.size();
        unordered_map<string, int> m2;
        int mi = l1 + l2 + 10;
        vector<string> ans;
        for (int i = 0; i < l2; i++) {
            m2[list2[i]] = i;
        }
        for (int i = 0; i < l1; i++) {
            if (m2.count(list1[i])) {
                if (mi > i + m2[list1[i]]) {
                    ans.clear();
                    mi = i + m2[list1[i]];
                    ans.push_back(list1[i]);
                } else if (mi == i + m2[list1[i]]) {
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};