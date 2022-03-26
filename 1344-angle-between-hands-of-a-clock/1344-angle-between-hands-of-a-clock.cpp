class Solution {
public:
    double angleClock(int hour, int minutes) {
       double(abs(5.5*minutes - 30*hour));
        if(double(abs(5.5*minutes - 30*hour))>180)
            return 360-double(abs(5.5*minutes - 30*hour));
        else
            return double(abs(5.5*minutes - 30*hour));
    
    }
};