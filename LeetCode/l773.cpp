class Solution {
public:
    int nx[6]={0},v[50000]={0},s[50000]={0},cal;
    void fillnx(int x){
        for(int i=0;i<6;i++){
            nx[i]=x%6;
            x/=6;
        }
    }
    void calc(){
        cal=0;
        for(int i=5;i>=0;i--){
            cal=cal*6+nx[i];
        }
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        memset(s,0x3f, sizeof(s));
        int fs=board[0][0]+board[0][1]*6+board[0][2]*6*6+
        board[1][0]*6*6*6+board[1][1]*6*6*6*6+board[1][2]*6*6*6*6*6;
        queue<int> q;
        q.push(fs);
        s[fs]=0;
        while(!q.empty()){
            int h=q.front();
            q.pop();
            if(v[h])continue;
            v[h]=1;
            fillnx(h);
            if(nx[0]==0){
                swap(nx[0],nx[1]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[1],nx[0]);
                swap(nx[0],nx[3]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[3],nx[0]);
            }else if(nx[1]==0){
                swap(nx[0],nx[1]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[1],nx[0]);
                swap(nx[1],nx[2]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[1],nx[2]);
                swap(nx[1],nx[4]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[1],nx[4]);
            }else if(nx[2]==0){
                swap(nx[2],nx[1]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[1],nx[2]);
                swap(nx[5],nx[2]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[2],nx[5]);
            }else if(nx[3]==0){
                swap(nx[3],nx[4]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[4],nx[3]);
                swap(nx[0],nx[3]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[3],nx[0]);
            }else if(nx[4]==0){
                swap(nx[3],nx[4]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[3],nx[4]);
                swap(nx[4],nx[5]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[4],nx[5]);
                swap(nx[1],nx[4]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[1],nx[4]);
            }else if(nx[5]==0){
                swap(nx[5],nx[4]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[4],nx[5]);
                swap(nx[5],nx[2]);
                calc();
                if(!v[cal]){
                    q.push(cal);
                    s[cal]=s[h]+1;
                }
                swap(nx[2],nx[5]);
            } 

        }
        nx[0]=1,nx[1]=2,nx[2]=3,nx[3]=4,nx[4]=5,nx[5]=0;
        calc();
        if(s[cal]>=0x3f3f3f3f)return -1;
        return s[cal];
    }
};