class Solution {
   public:
    vector<string> generatePossibleNextMoves(string currentState) {
        int l = currentState.size();
        vector<string> ans;
        for (int i = 1; i < l; i++) {
            if (currentState[i] == currentState[i - 1] &&
                currentState[i] == '+') {
                currentState[i] = currentState[i - 1] = '-';
                ans.push_back(currentState);
                currentState[i] = currentState[i - 1] = '+';
            }
        }
        return ans;
    }
};