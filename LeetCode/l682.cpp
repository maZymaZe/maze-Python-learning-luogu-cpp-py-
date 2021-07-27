class Solution {
   public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        int l = ops.size(), tot = 0;
        for (int i = 0; i < l; i++) {
            if (ops[i][0] == 'C')
                v.pop_back();
            else if (ops[i][0] == 'D')
                v.push_back(v.back() * 2);
            else if (ops[i][0] == '+') {
                int tt = v.size();
                v.push_back(v[tt - 1] + v[tt - 2]);
            } else {
                v.push_back(stoi(ops[i]));
            }
        }
        l = v.size();
        for (int i = 0; i < l; i++)
            tot += v[i];
        return tot;
    }
};