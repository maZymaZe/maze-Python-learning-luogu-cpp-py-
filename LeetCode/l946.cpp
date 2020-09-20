class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int l1 = pushed.size(), l2 = popped.size();
        if(l1==l2&&l1==0)return true;
        int p1 = 0, p2 = 0;
        while (1) {
            if ((!s.empty()) && s.top() == popped[p2]) {
                s.pop();
                p2++;
                if (p2 == l2)
                    return true;
            } else {
                if (p1 < l1)
                    s.push(pushed[p1]), p1++;
                else
                    return false;
            }
        }
        return false;
    }
};