int v[300]={0};
int cmp(const char&a,const char&b){
    if(v[a]<v[b])return 1;
    return 0;
}
class Solution {
public:
    string customSortString(string S, string T) {
        for(int i=0;i<S.size();i++){
            v[S[i]]=i;
        }
        sort(T.begin(),T.end(),cmp);
        return T;
    }
};