class Solution {
public:
    int minPartitions(string n) {
        int freq[10]={0};
        
        for(int i=0;i<n.size();i++)
        {
            int index=n[i]-'0';
            freq[index]++;
        }
        
        int ans=0;
        
        for(int i=9;i>=0;i--)
        {
            if(freq[i]>0)
            {
                ans=i;
                break;
            }
        }
        
        return ans;
    }
};