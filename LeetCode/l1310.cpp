class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int l=arr.size();
        vector <int> ps(l+1);
        for (int i=0; i<l; i++){
            ps[i+1]=ps[i]^arr[i];
        }
        l=queries.size();
        vector <int> res(l);
        for (int i=0; i<l; i++){
            res[i]=(ps[queries[i][1]+1]^ps[queries[i][0]]);
        }
        return res;
        
    }
};