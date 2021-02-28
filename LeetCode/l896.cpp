class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int f=0,l=A.size();
        for(int i=1;i<l;i++){
            if(A[i]>A[i-1]){
                if(f==-1)return false;
                if(f==0)f=1;
            }else if(A[i]<A[i-1]){
                if(f==1)return false;
                if(f==0)f=-1;
            }
        }
        return true;
    }
};