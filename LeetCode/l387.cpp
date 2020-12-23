class Solution {
public:
    int firstUniqChar(string s) {
        int c[26]={0},l=s.size();
        for(int i=0;i<l;i++)c[s[i]-'a']++;
        for(int i=0;i<l;i++)if(c[s[i]-'a']==1)return i;
        return -1;
    }
};