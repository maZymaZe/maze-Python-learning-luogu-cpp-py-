class Solution {
public:
    int minimumOperations(string leaves) {
        int l=leaves.size();
        int g=(leaves[0]=='y'?1:-1);
        int gmin=g;
        int ans=l;
        for(int i=1;i<l; i++){
            int y=(leaves[i]=='y');
            g+=2*y-1;
            if(i!=l-1)ans=min(ans,gmin-g);
            gmin=min(gmin,g);
        }
        return ans+(g+l)/2;
    }
};