class Solution {
   public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& it : operations)
            (it[1] == '+') ? x++ : x--;
        return x;
    }
};