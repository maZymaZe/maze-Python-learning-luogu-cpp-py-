class Solution {
public:
    int convertInteger(int A, int B) {
        int ans=0;
        for(int i=1;i<=32;i++){
            ans+=((A^B)&1);
            A>>=1,B>>=1;
        }
        return ans;
    }
};