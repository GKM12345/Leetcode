bool cmp(string a, string b)
{
    return (a+b)>(b+a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n=nums.size();
        vector<string> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i]=to_string(nums[i]);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        string ans="";
        for(int i=0;i<n;i++)
        {
            ans+=v[i];
        }
        
        if(ans[0]=='0') return "0";
        
        return ans;
        
    }
};