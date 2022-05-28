class Solution {
public:
    bool isPowerOfTwo(int n) {
        
       if(n<=0) return false;
        
        long long i=1;
        while(i<=n)
        {
            if(n==i) return true;
            i=i*2;
        }
        
        return false;
        
    }
};