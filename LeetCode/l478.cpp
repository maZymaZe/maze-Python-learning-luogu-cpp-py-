class Solution {
public:
    const long double pi= acos(-1);
    mt19937 rng{random_device{}()};
    std::uniform_real_distribution<long double> rr{0,1},a{0,2*pi};
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r=radius,x=x_center,y=y_center;
    }
    
    vector<double> randPoint() {
        long double tr=sqrt(rr(rng)),ta=a(rng);
        return {(double)(x+tr*r*cosl(ta)),(double)(y+tr*r*sinl(ta))};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */