class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int l=A.size();
        int floor=l;
        for(int i=l-1;i>=2;i--){
            floor=min(floor,A[i]);
            if(A[i-2]>floor)return false;
        }
        return true;
    }
};