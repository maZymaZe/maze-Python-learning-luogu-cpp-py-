class Solution {
   public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> q;
        int l = heights.size();
        for (int i = 1; i < l; i++) {
            int nd = heights[i] - heights[i - 1];
            if (nd <= 0)
                continue;
            if (ladders) {
                ladders--;
                q.push(nd);
            } else {
                q.push(nd);
                if (bricks >= q.top()) {
                    bricks -= q.top();
                    q.pop();
                } else
                    return i - 1;
            }
        }
        return l - 1;
    }
};