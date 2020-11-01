struct gp{
    int x,y;
    bool operator<(const gp& t){
        if(x+y<t.x+t.y)return true;
        else if(x+y==t.x+t.y&&x>t.x)return true;
        return false;
    }
};
class Solution {
public:
    vector<gp> p;
    vector<int> ans;
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums[i].size();j++){
                p.push_back({i,j});
            }
        }
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++){
            ans.push_back(nums[p[i].x][p[i].y]);
        }
        return ans;
    }
};