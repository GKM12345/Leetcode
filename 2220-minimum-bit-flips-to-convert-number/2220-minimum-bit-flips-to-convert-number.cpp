class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int num=start^goal;
        int ans=0;
        while(num!=0)
        {
            int rmsb=num&-num;
            num=num-rmsb;
            ans++;
        }
        
        return ans;
        
    }
};