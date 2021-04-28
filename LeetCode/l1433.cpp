class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(),s2.end());
        int f=0,l=s1.length();
        for(int i=0;i<l;i++){
            if(s1[i]>s2[i]){
                f=1;
                break;
            }
        }
        if(f==0)return true;
        for(int i=0;i<l;i++){
            if(s1[i]<s2[i]){
                return false;
            }
        }
        return true;
    }
};