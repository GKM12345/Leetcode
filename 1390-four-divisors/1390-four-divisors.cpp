class Solution {
public:
    int sumFourDivisors(vector<int>& arr) {
        
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            int count=0;
            for(int j=1;j*j<=arr[i];j++)
            {
                if(arr[i]%j==0)
                {
                    if(j*j==arr[i])
                    {
                        count+=1;
                        sum+=j;
                    }
                    else
                    {
                        count+=2;
                        sum+=j;
                        sum+=arr[i]/j;
                    }
                    
                }
            }
            if(count==4)
            {
                ans+=sum;
            }
        }

        return ans;
        
    }
};