const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,m,r;
class Solution {
public:
    void ff(vector<vector<int>>& image, int sr, int sc, int newColor){
        image[sr][sc]=newColor;
        for(int i=0;i<4;i++){
            int nx=sr+dx[i],ny=sc+dy[i];
            if(nx>=0&&nx<n&&ny<m&&ny>=0&&image[nx][ny]==r){
                ff(image,nx,ny,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size(),m=image[0].size();r=image[sr][sc];
        if(r==newColor)return image;
        ff(image, sr,  sc,  newColor);
        return image;
    }
};