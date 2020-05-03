int b[1002];
int cmp(const int&a,const int &c){
    if(b[a]&&b[c])return b[a]<b[c];
    if(b[a]==0&&b[c])return false;
    if(b[a]&&b[c]==0)return true;
    return a<c;
}
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        memset(b,0,sizeof(b));
        for(int i=0;i<arr2.size();i++)b[arr2[i]]=i+1;
        sort(arr1.begin(),arr1.end(),cmp);
        return arr1;
    }
};