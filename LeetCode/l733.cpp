struct pr{
    int x,y;
};
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc])return image;
        queue<pr> q;
        int md=image[sr][sc],n=image.size(),m=image[0].size();
        q.push({sr,sc});
        while(!q.empty()){          
            pr t=q.front();
            image[t.x][t.y]=newColor;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=t.x+dx[i],ny=t.y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&image[nx][ny]==md){
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};