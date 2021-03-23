class Solution {
   public:
    int tr;
    bool ck(string&x, string&y,int z){
        for(int i=0;i<=z;i++){
            if(x[i]!=y[i])return false;
        }
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        int len = searchWord.size(), l = 0, r, sz = products.size();
        tr=sz;
        vector<vector<string>> result;
        for (int i = 0; i < len; i++) {
            vector<string> ans;
            while (l < sz) {
                if (i >= products[l].size()) {
                    l++;
                    continue;
                }
                if (products[l][i] == searchWord[i]) {
                    break;
                }
                if (products[l][i] > searchWord[i]) {
                    break;
                }
                l++;
            }
            if (l == sz) {
                result.push_back(ans);
                continue;
            }
            r = l;
            for (int j = 0; j < 3; j++) {
                if(r+j >= sz) break;
                if(products[r+j].size()<=i)break;
                if (products[r + j][i] != searchWord[i]) {
                    break;
                }
                if(r+j>=tr){
                    break;
                }
                if(!ck(products[r+j],searchWord,i)){
                    tr=r+j;
                    break;
                }
                ans.push_back(products[r + j]);
            }
            result.push_back(ans);
        }
        return result;
    }
};