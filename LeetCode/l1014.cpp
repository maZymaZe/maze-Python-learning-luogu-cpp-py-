class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int l=A.size(),m1=0,m2=0;
        for(int i=0;i<l;i++)m1=max(m1,m2+A[i]-i),m2=max(A[i]+i,m2);
        return m1;
    }
};