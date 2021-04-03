class Solution {
public:
    int q[80]={0};
    int hash(int x,int y){return x*8+y;}
    int qx(int hs){return hs/8;}
    int qy(int hs){return hs%8;}
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        for(auto v:queens){q[hash(v[0],v[1])]=1;}
        vector<vector<int>> ans;
        int tx=king[0],ty=king[1];
        while(tx>=0&&!q[hash(tx,ty)]){tx--;}
        if(tx>=0)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(ty>=0&&!q[hash(tx,ty)]){ty--;}
        if(ty>=0)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(tx<8&&!q[hash(tx,ty)]){tx++;}
        if(tx<8)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(ty<8&&!q[hash(tx,ty)]){ty++;}
        if(ty<8)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(tx<8&&ty<8&&!q[hash(tx,ty)]){tx++;ty++;}
        if(tx<8&&ty<8)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(tx>=0&&ty<8&&!q[hash(tx,ty)]){tx--;ty++;}
        if(tx>=0&&ty<8)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(tx<8&&ty>=0&&!q[hash(tx,ty)]){tx++;ty--;}
        if(tx<8&&ty>=0)ans.push_back({tx,ty});

        tx=king[0],ty=king[1];
        while(tx>=0&&ty>=0&&!q[hash(tx,ty)]){tx--;ty--;}
        if(tx>=0&&ty>=0)ans.push_back({tx,ty});

        return ans;
    }
};