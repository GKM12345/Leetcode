class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n=arr.size();
        int freq[100001]={0};
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        
        sort(freq,freq+100001,greater<int>());
        
        int ans=0;
        int sum=0;
        
        for(int i=0;i<=100000;i++)
        {
            if(sum>=n/2)
            {
                break;
            }
            sum+=freq[i];
            ans+=1;
        }
        
        return ans;
        
        
    }
};