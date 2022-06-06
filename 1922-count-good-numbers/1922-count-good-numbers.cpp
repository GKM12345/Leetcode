class Solution {
    
    const int mod=1e9+7;
    
    long long power(long long a,long long n)
    {
        if(n==0)
        {
            return 1;
        }
        long long ans1=power(a,n/2);
        long long ans;
        if(n&1)
        {
            ans= ((ans1%mod) *(ans1%mod) *(a%mod))%mod;
        }
        else
        {
            ans=((ans1%mod) *(ans1%mod))%mod;
        }
        return ans%mod;
    }
    
public:
    int countGoodNumbers(long long n) {
        
       long long n1=n/2+n%2;
       long long n2=n/2;
        long long ans1=power(5,n1);
        long long ans2=power(4,n2);
        int ans= ((ans1%mod) * (ans2%mod))%mod;
        return ans;
    }
};