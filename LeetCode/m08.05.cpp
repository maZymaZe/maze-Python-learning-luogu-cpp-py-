class Solution {
public:
    int rc(int A,int B,int ans){
        if(A==0||B==0)return ans;
        if(B&1)ans+=A;
        B>>=1;
        A<<=1;
        return rc(A,B,ans);
    }
    int multiply(int A, int B) {
        return rc(A,B,0);
    }
};