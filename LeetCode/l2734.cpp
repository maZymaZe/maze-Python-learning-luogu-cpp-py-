class Solution {
   public:
    string smallestString(string s) {
        int l=s.size(),p=0;
        while(p<l&&s[p]=='a'){
            p++;
        }
        if(p==l){
            s[l-1]='z';
            return s;
        }
        while(p<l&&s[p]!='a'){
            s[p]=s[p]-1;
            p++;
        }
        return s;
    }
};