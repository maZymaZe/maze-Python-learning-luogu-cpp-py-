class Solution {
   public:
    vector<string> trulyMostPopular(vector<string>& names,
                                    vector<string>& synonyms) {
        unordered_map<string, int> mp;
        for (int i = 0; i < names.size(); i++) {
            int k = names[i].find("(");
            string name = names[i].substr(0, k);
            int times = stoi(names[i].substr(k + 1, names[i].size() - k - 2));
            mp[name] = times;
        }
        unordered_map<string, string> fa;
        for (int i = 0; i < synonyms.size(); i++) {
            int k = synonyms[i].find(",");
            string name1 = synonyms[i].substr(1, k - 1);
            string name2 =
                synonyms[i].substr(k + 1, synonyms[i].size() - k - 2);
            while (fa.find(name1) != fa.end())
                name1 = fa[name1];
            while (fa.find(name2) != fa.end())
                name2 = fa[name2];
            if (name1 != name2) {
                int num = mp[name1] + mp[name2];
                string faname = name1 < name2 ? name1 : name2;
                string sonname = name1 < name2 ? name2 : name1;
                fa[sonname] = faname;
                mp.erase(sonname);
                mp[faname] = num;
            }
        }
        vector<string> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->first + "(" + to_string(it->second) + ")");
        }
        return res;
    }
};
