class Solution {
   public:
    int distanceBetweenBusStops(vector<int>& distance,
                                int start,
                                int destination) {
        int t1 = 0, t2 = 0, p1 = start, p2 = start, n = distance.size();
        while (p1 != destination) {
            t1 += distance[p1];
            p1++;
            if (p1 == n)
                p1 = 0;
        }
        while (p2 != destination) {
            --p2;
            if (p2 < 0)
                p2 = n - 1;
            t2 += distance[p2];
        }
        return min(t1, t2);
    }
};