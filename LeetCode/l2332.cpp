class Solution {
   public:
    int latestTimeCatchTheBus(vector<int>& buses,
                              vector<int>& passengers,
                              int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int p = 0, lb = buses.size(), lp = passengers.size();
        vector<vector<int>> mp(lb);
        for (int i = 0; i < lp; i++) {
            while (p < lb && passengers[i] > buses[p])
                p++;
            if (lb == p)
                break;
            mp[p].push_back(i);
            if (mp[p].size() == capacity)
                p++;
        }
        if (mp[lb - 1].empty() ||
            (mp[lb - 1].size() < capacity &&
             passengers[mp[lb - 1].back()] != buses[lb - 1]))
            return buses[lb - 1];
        int q = mp[lb - 1].back();
        while (q && passengers[q] == passengers[q - 1] + 1)
            q--;
        return passengers[q] - 1;
    }
};