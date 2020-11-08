class Solution {
   public:
    const int d[8][3] = {{1, 1, 1},  {1, 1, -1},  {1, -1, 1},  {1, -1, -1},
                         {-1, 1, 1}, {-1, 1, -1}, {-1, -1, 1}, {-1, -1, -1}};
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int l = arr1.size(), ma[8], mi[8], res;
        for (int j = 0; j < 8; j++) {
            ma[j] = 0x80000000, mi[j] = 0x7FFFFFFF;
            for (int i = 0; i < l; i++) {
                ma[j]=max(ma[j],arr1[i]*d[j][0]+arr2[i]*d[j][1]+i*d[j][2]);
                mi[j]=min(mi[j],arr1[i]*d[j][0]+arr2[i]*d[j][1]+i*d[j][2]);
            }
        }
        res=0x80000000;
        for(int i=0;i<8;i++){
            res=max(res,ma[i]-mi[i]);
        }
        return res;
    }
};