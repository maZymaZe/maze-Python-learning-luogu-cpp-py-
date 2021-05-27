class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string res;
        res+=word;int cur=0;
        while(sequence.find(res)!=string::npos){
            cur++;
            res+=word;
        }return cur;
    }
};