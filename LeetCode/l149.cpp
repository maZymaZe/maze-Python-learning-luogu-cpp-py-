class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int l=points.size();
        if(l<3)return l;
        int ret=0;
        for(int i=0;i<l;i++){
            if(ret>=l-1||ret>l/2)break;
            unordered_map<int,int> mp;
            for(int j=i+1;j<l;j++){
                int x=points[i][0]- points[j][0];
                int y=points[i][1]- points[j][1];
                if(x==0)y=1;
                else if(y==0)x=1;
                else {
                    if(y<0)x=-x,y=-y;
                    int g=__gcd(x,y);
                    x/=g,y/=g;
                }
                mp[y+x*20001]++;
            }
            int maxn=0;
            for(auto&[_,num]:mp){
                maxn=max(maxn,num+1);
            }
            ret=max(ret,maxn);
        }
        return ret;
    }
};