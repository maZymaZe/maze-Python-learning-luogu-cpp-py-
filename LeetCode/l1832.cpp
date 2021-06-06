class Solution {
public:
    bool checkIfPangram(string sentence) {
        int c[26]={0},t=0;
        for(char a:sentence){
            if(c[a-'a']==0)t++,c[a-'a']++;
        }
        return t==26;
    }
};