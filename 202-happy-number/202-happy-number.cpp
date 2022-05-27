class Solution {
    
    long long squareofdigit(long long n)
    {
        long long sum=0;
        while(n>0)
        {
            long long rem=n%10;
            sum=sum+rem*rem;
            n=n/10;
        }
        
        return sum;
    }
    
public:
    bool isHappy(int n) {
        
        unordered_set<long long> S;
        long long n1=n;
        S.insert(n1);
        while(n1!=1)
        {
            n1=squareofdigit(n1);
            if(S.count(n1)>0)
            {
                return false;
            }
            else
            {
                S.insert(n1);
            }
        }
        
        return true;
        
    }
};