class OrderedStream {
   public:
    OrderedStream(int n) {
        lg.resize(n);
        np = 0;
    }
    int np;
    vector<string> lg;
    vector<string> insert(int idKey, string value) {
        lg[idKey - 1] = value;
        vector<string> ans;
        while (np < lg.size() && lg[np].size()) {
            ans.push_back(lg[np]);
            np++;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */