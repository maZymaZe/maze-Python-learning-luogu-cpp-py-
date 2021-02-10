class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length(), l2=s2.length();
        if(l1>l2) return false;
        int a[26]={0},b[26]={0},m=0;
        for(int i=0;i<l1;i++)a[s1[i]-'a']++;
        for(int i=0;i<l2;i++)b[s2[i]-'a']++;
        for(int i=0;i<26;i++)m+=(a[i]==b[i]?1:0);
        if(m==26)return true;
        for(int i=l1;i<l2;i++){
            int t=s2[i]-'a';
            b[t]++;
            if(b[t]==a[t])m++;
            else if(b[t]==a[t]+1)m--;
            t=s2[i-l1]-'a';
            b[t]--;
            if(b[t]==a[t])m++;
            else if(b[t]==a[t]-1)m--;
            if(m==26)return true;
        }
        return false;
    }
};