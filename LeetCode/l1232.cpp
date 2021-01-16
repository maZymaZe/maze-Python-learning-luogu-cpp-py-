class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int px=coordinates[0][0],l=coordinates.size(),f=0,py=coordinates[0][1];
        for(int i=1;i<l;i++)if(coordinates[i][0]!=px){f=i;break;}
        int qx=coordinates[f][0],qy=coordinates[f][1];
        for(int i=1;i<l;i++)if((coordinates[i][0]-px)*(qy-py)!=(coordinates[i][1]-py)*(qx-px))return false;
        return true;
    }
};