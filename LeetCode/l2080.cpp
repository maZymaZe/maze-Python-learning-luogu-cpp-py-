class RangeFreqQuery {
   public:
    vector<int> oc[10003];
    RangeFreqQuery(vector<int>& arr) {
        int l = arr.size();
        for (int i = 0; i < l; i++)
            oc[arr[i]].push_back(i);
    }

    int query(int left, int right, int value) {
        return (upper_bound(oc[value].begin(), oc[value].end(), right) -
                lower_bound(oc[value].begin(), oc[value].end(), left));
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */