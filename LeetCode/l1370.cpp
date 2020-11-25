class Solution {
public:
    string sortString(string s) {
        int c[26]={0},l=s.size(),t=0;
        string result(l);
        for(int i=0;i<l;i++)c[s[i]-'a']++;
        while(l){
            for(int i=0;i<26;i++)if(c[i])result[t++]=c[i]+'a',c[i]--,l--;
            for(int i=25;i>=0;i--)if(c[i])result[t++]=c[i]+'a',c[i]--,l--;
        }return result;
    }
};