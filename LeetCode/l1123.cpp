class Solution {
   public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int l = folder.size(), p;
        vector<string> ans;
        if (l == 0)
            return ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);
        p = 0;
        for (int i = 1; i < l; i++) {
            int f1 = folder[i].size(), f2 = folder[p].size();
            if (f1 <= f2)
                ans.push_back(folder[i]), p = i;
            else {
                bool flag = false;
                if(folder[i][f2]!='/'){
                     ans.push_back(folder[i]), p = i;
                     continue;
                }
                for (int j = 0; j < f2; j++) {
                    if (folder[i][j] != folder[p][j]) {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    ans.push_back(folder[i]), p = i;
            }
        }
        return ans;
    }
};