class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int l=A.size();
        vector<int> ma(l),mi(l);
        ma[0]=A[0];
        for(int i=1;i<l;i++){
            ma[i]=max(ma[i-1],A[i]);
        }
        mi[l-1]=A[l-1];
        for(int i=l-2;i>=0;i--){
            mi[i]=min(mi[i+1],A[i]);
        }
        for(int i=1;i<l;i++){
            if(mi[i]>=ma[i-1])return i;
        }
        return 0;
    }
};