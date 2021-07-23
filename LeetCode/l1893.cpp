bool cmp(const vector<int>& a, const vector<int>& b){
    return a[0]< b[0];
}
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(),cmp);
        int l=ranges.size();
        for(int i=0; i<l;i++){
            if(ranges[i][0]<=left){
                if(ranges[i][1]<right){
                    left=max(ranges[i][1]+1,left);
                }else return true;
            }
            else return false;
        }
        return false;
    }
};