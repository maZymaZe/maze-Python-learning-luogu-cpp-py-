class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> s;
        for(int i=0;i<=46340;i++){
            s.insert(i*i);
            if(s.count(c-i*i))return true;
        }
        return false;
    }
};