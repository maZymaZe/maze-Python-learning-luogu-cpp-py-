class Solution {
public:
    double angleClock(int hour, int minutes) {
        long double t1=hour*60+minutes,t2=minutes;
        t1/=60*12,t2/=60;
        t1*=360,t2*=360;
        return min(fabs(t1-t2),-fabs(t1-t2)+360);
    }
};