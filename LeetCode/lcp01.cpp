class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int c=0;
        for(int i=0;i<3;i++){
            c+=(guess[i]==answer[i])?1:0;
        }
        return c;
    }
};