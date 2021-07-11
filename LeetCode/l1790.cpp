class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0,l=s1.length(),p[2];
        for(int i=0; i < l; i++){
            if(s1[i]!=s2[i]){
                if(c==2)return false;
                p[c++]=i;
            }
        }
        if(c==0)return true;
        return (c==2&&(s1[p[0]]==s2[p[1]]&&s1[p[1]]==s2[p[0]]));
    }
};