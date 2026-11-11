class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=abs(30*hour -5.5*minutes);
        return min(x,360-x);
    }
};