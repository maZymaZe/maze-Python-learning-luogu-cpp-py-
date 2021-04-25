class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        for(int p=0;;p++){
            long long tmp=pow(x,p);
            if(tmp>bound)break;
            for(int j=0;;j++){
                long long tmp2=pow(y,j);
                if(tmp+tmp2>bound)break;
                res.push_back(tmp2+tmp);
                if(y==1)break;
            }
            if(x==1)break;
        }
        sort(res.begin(),res.end());
        vector<int> ret(res.begin(),unique(res.begin(),res.end()));
        return ret;
    }
};