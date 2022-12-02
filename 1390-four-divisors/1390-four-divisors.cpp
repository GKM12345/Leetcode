class Solution {
public:
    int sumFourDivisors(vector<int>& arr) {
        
        int ans=0;
        int n=arr.size();
        // ll ans=0;
	
	for(int i=0;i<n;i++)
	{
		long long val=0;
		long long cnt=0;
		for(int j=1;j*j<=arr[i];j++)
		{
			if(arr[i]%j==0)
			{
                if(j*j==arr[i])
                {
                    cnt+=1;
                    val+=j;
                }
                else
                {
                    cnt+=2;
				    val+=j;
				    val+=arr[i]/j;
                }
			}
		}
		
		if(cnt==4)
		{
			ans+=val;
		}
	}
	
	//cout << ans << endl;

        return ans;
        
    }
};