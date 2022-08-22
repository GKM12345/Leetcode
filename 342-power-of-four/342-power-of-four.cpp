class Solution {
public:
    bool isPowerOfFour(int n) {
        
        long long n1=n;
        
        if((n1&(n1-1))==0 && n%3==1) return true;
        return false;
        
    }
};