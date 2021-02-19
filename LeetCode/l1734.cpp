class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int l=encoded.size();
        vector<int> result(l+1);
        int t=encoded[0],tt=0;
        for(int i=1;i<=l+1;i++)tt^=i;
        result[0]=encoded[0];
        for(int i=1;i<l;i++){
            t^=encoded[i];
            result[0]^=t;
        }
        result[0]^=tt;
        for(int i=1;i<=l;i++){
            result[i]=encoded[i-1]^result[i-1];
        }
        return result;
    }
};