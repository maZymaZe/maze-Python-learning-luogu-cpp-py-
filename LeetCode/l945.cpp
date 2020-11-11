class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()==0)return 0;
        sort(A.begin(), A.end());
        int l=A.size();
        bool f=true;
        int pre=A[0],ans=0;
        for(int i=1;i<l;i++){
            if(A[i]>pre){
                f=true;
                pre=A[i];
            }else{
                pre++;
                ans+=pre-A[i];
            }
        }
        return ans;
    }
};