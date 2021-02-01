class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int sa=0,sb=0,del,la=A.size(),lb=B.size();
        for(int i=0;i<la;i++)sa+=A[i],mp[A[i]]=i+1;
        for(int i:B)sb+=i;
        del=sa-sb;
        del/=2;
        for(int i=0;i<lb;i++){
            if(mp.count(B[i]+del)){
                return{B[i]+del,B[i]};
            }
        }
        return{};
        
    }
};