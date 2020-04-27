class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int n,m;
        n=A.size(),m=A[0].size();
        deque<int> x,y;
        int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        for(int i=0;i<n;i++){
            if(A[i][0]==1){
                x.push_back(i);y.push_back(0);A[i][0]=2;
                while(!x.empty()){
                    int xx=x.front(),yy=y.front();
                    for(int j=0;j<4;j++){
                        if(xx+dx[j]<n&&xx+dx[j]>=0&&dy[j]+yy<m&&dy[j]+yy>=0&&A[xx+dx[j]][yy+dy[j]]==1)
                        x.push_back(xx+dx[j]),y.push_back(yy+dy[j]),A[xx+dx[j]][yy+dy[j]]=2;
                    }
                    x.pop_front();y.pop_front();
                }
            }
            if(A[i][m-1]==1){
                x.push_back(i);y.push_back(m-1);A[i][m-1]=2;
                while(!x.empty()){
                    int xx=x.front(),yy=y.front();
                    for(int j=0;j<4;j++){
                        if(xx+dx[j]<n&&xx+dx[j]>=0&&dy[j]+yy<m&&dy[j]+yy>=0&&A[xx+dx[j]][yy+dy[j]]==1)
                        x.push_back(xx+dx[j]),y.push_back(yy+dy[j]),A[xx+dx[j]][yy+dy[j]]=2;
                    }
                    x.pop_front();y.pop_front();
                }
            }
        }
        for(int i=0;i<m;i++){
            if(A[0][i]==1){
                x.push_back(0);y.push_back(i);A[0][i]=2;
                while(!x.empty()){
                    int xx=x.front(),yy=y.front();
                    for(int j=0;j<4;j++){
                        if(xx+dx[j]<n&&xx+dx[j]>=0&&dy[j]+yy<m&&dy[j]+yy>=0&&A[xx+dx[j]][yy+dy[j]]==1)
                        x.push_back(xx+dx[j]),y.push_back(yy+dy[j]),A[xx+dx[j]][yy+dy[j]]=2;
                    }
                    x.pop_front();y.pop_front();
                }
            }
            if(A[n-1][i]==1){
                x.push_back(n-1);y.push_back(i);A[n-1][i]=2;
                while(!x.empty()){
                    int xx=x.front(),yy=y.front();
                    for(int j=0;j<4;j++){
                        if(xx+dx[j]<n&&xx+dx[j]>=0&&dy[j]+yy<m&&dy[j]+yy>=0&&A[xx+dx[j]][yy+dy[j]]==1)
                        x.push_back(xx+dx[j]),y.push_back(yy+dy[j]),A[xx+dx[j]][yy+dy[j]]=2;
                    }
                    x.pop_front();y.pop_front();
                }
            }
        }
        int cnt;
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};