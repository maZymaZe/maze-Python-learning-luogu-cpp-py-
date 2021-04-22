class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int a[3]={A[0], A[1],A[2]},l=A.size();
        if(a[0]==a[1]||a[0]==a[2])return a[0];
        if(a[1]==a[2])return a[1];
        for(int i=3;i<l;i++){
            if(A[i]==a[0]||A[i]==a[1]||A[i]==a[2])return A[i];
            a[i%3]=A[i];
        }
        return 0;
    }
};