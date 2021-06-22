class Solution {
public:
    long long hs(int x, int y){
        return x*10005+y;
    }
    bool isPathCrossing(string path) {
        unordered_set<long long> mp;
        mp.insert(0);
        int x=0,y=0;
        int l=path.size();
        for(int i=0;i<l;i++){
            if(path[i]=='N')x--;
            else if(path[i]=='S')x++;
            else if(path[i]=='E')y++;
            else if(path[i]=='W')y--;
            long long t=hs(x,y);
            if(mp.count(t))return true;
            mp.insert(t);
        }
        return false;
    }
};