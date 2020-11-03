class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int cnt[28]={0},m=-1,p;
        int len=s.length(),r=t.length();
        if(len!=r)return false;
        for(int i=0; i<len; i++){
            cnt[(t[i]-s[i]+26)%26]++;
        }
        for(int i=1; i<26; i++){
            if(cnt[i]>=m){
                m=cnt[i];
                p=i;
            }
        }
        long long ned=(m-1)*26+p;
        return ned<=k;
    }
};