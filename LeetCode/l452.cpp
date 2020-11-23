class Solution {
public:
    static bool cmp(const std::vector<int> &a, const std::vector<int> &b) {
        if(a[1]<b[1])return true;
        if(a[1]==b[1])return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1,l=points.size(),p=1,m;
        if(!l)return 0;
        sort(points.begin(),points.end(),cmp);
        m=points[0][1];
        while(p<l){
            if(m>=points[p][0]&&m<=points[p][1])p++;
            else m=points[p][1],p++,ans++;
        }
        return ans;
    }
};