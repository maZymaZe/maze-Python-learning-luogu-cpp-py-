class SnapshotArray {
   public:
    vector<vector<int>> v, id;
    int times = 0;
    SnapshotArray(int length) {
        v.resize(length), id.resize(length);
        for (int i = 0; i < length; i++) {
            v[i].push_back(0);
            id[i].push_back(-1);
        }
    }

    void set(int index, int val) {
        if (times != id[index].back()) {
            v[index].push_back(val), id[index].push_back(times);
        } else
            v[index].back() = val;
    }

    int snap() { return times++; }

    int get(int index, int snap_id) {
        int nd = lower_bound(id[index].begin(), id[index].end(), snap_id + 1) -
                 id[index].begin() - 1;
        return v[index][nd];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */