class Solution {
   public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> strs;
        strs.reserve(20);
        string curr;
        while (getline(ss, curr, '/')) {
            if (curr != "." && curr != "") {
                if (curr != "..")
                    strs.push_back(curr);
                else if (!strs.empty())
                    strs.pop_back();
            }
        }
        if (!strs.empty()) {
            string res = "";
            for (auto& x : strs) {
                res += '/';
                res += x;
            }
            return res;
        }
        return "/";
    }
};