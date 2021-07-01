struct pr{
    int a,b;
    bool operator <(const pr& x)const {
        return (long long)(b-a)*x.b*(x.b+1)<(long long)(x.b-x.a)*b*(b+1);
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pr> pq;
        for(const auto& it:classes){
            pr x;
            x.a=it[0],x.b=it[1];
            pq.push(x);
        }
        for(int i=0;i<extraStudents;i++){
            pr x=pq.top();
            x.a++,x.b++;
            pq.pop();
            pq.push(x);
        }
        double s=0;
        while(!pq.empty()){
            pr x=pq.top();
            s+=1.0*x.a/x.b;
            pq.pop();
        }
        return s/classes.size();
    }
};