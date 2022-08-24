class Solution {
public:
    bool isPowerOfThree(int n) {
        
        long long no=1;
        while(no<n)
        {
            no=no*3;
        }
        if(no==n) return true;
        return false;
        
    }
};