class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m=matrix[0].size();
        if(!m)return false;
        int x=0,y=m-1;
        while(x>=0&&y>=0&&x<n&&y<m){
            if(matrix[x][y]==target)return true;
            if(matrix[x][y]>target)y--;
            else x++;
        }
        return false;
    }
};