const double delta = 0.98;
int n;
double ansx, ansy, ax, ay, t, ress;
void clear() {
    ax = ay = 0,ress=10000000000;
}
double cal(double x, double y, vector<vector<int>>& positions) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        double dx = x - positions[i][0], dy = y - positions[i][1];
        res += sqrt(dx * dx + dy * dy);
    }
    return res;
}
const int dx[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
void simulate_anneal(vector<vector<int>>& positions) {
    double x = ansx, y = ansy;
    t = 100;
    while (t > 1e-8) {
        for (int k = 0; k < 4; k++) {
            double X = x + dx[k][0]*t;
            double Y = y + dx[k][1]*t;
            double now = cal(X, Y, positions);
            double Delta = now - ress;
            if (Delta < 0) {
                ansx = X, ansy = Y;
                ress = now;
                x = X, y = Y;
            }//else if(exp(-Delta/t)*RAND_MAX>rand())x=X,y=Y;
        }
        
        t *= delta;
    }
}
void work(vector<vector<int>>& positions) {
    ansx = ax / n, ansy = ay / n;
    for (int i = 0; i < 5; i++)
        simulate_anneal(positions);
}

class Solution {
   public:
    double getMinDistSum(vector<vector<int>>& positions) {
        srand(8878787);
        clear();
        n = positions.size();
        for (int j = 0; j < n; j++) {
            ax += positions[j][0], ay += positions[j][1];
        }
        work(positions);
        return ress;
    }
};