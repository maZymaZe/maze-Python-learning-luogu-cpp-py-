class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int l=A.size(),t=1,pos=-1,cnt=0;
        vector<int> v(l);
        for(int i=0;i<l;i++){
            if(A[i]!=t){
                if(i+K>l)return -1;
                else{
                    t^=1;
                    v[i+K-1]=1;
                    cnt++;
                }
            }
            if(v[i])t^=1;
        }
        return cnt;
    }
};