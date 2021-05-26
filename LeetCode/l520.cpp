class Solution {
public:
    bool detectCapitalUse(string word) {
        int l=word.size(),c1=0,c2=0;
        for(int i=0;i<l;i++){
            if(word[i]<='Z')c1++;
            else c2++;
        }
        return c1==l||c2==l||(c1==1&&word[0]<='Z');
    }
};