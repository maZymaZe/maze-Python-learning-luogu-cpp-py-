class Solution {
   public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int l = skills.size();
        k = min(k, l);
        int cur = skills[0], curid = 0, cnt = 0;
        queue<int> q, id;
        for (int i = 1; i < l; i++)
            q.push(skills[i]), id.push(i);
        while (cnt < k) {
            if (cur > q.front()) {
                id.push(id.front());
                id.pop();
                q.push(q.front());
                q.pop();
                cnt++;
            } else {
                q.push(cur);
                id.push(curid);
                cur = q.front();
                curid = id.front();
                cnt = 1;
                q.pop();
                id.pop();
            }
        }
        return curid;
    }
};