class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        int minhrs=5*hour;
        int val=minhrs-minutes;
        double ans;
        double minangle=(30.0*minutes)/60.0;
        
        if(val>=0)
        {
            if(val>=30)
            {
                val=60-val;
                ans=val*6.0;
                ans=ans-minangle;
            }
            else
            {
                ans=val*6.0;
                ans=ans+minangle;
            }
        }
        else
        {
            val=abs(val);
            if(val<=30)
            {
                ans=val*6.0;
                ans=ans-minangle;
            }
            else
            {
                val=60-val;
                ans=val*6.0;
                ans=ans+minangle;
            }
        }
        if(ans>180.0)
        {
            return 360-ans;
        }
        return abs(ans);
        
    }
};