class Solution {
    
    void helper(string digits, string val, vector<string> &ans, string str[])
    {
        if(digits.size()==0)
        {
            ans.push_back(val);
            return;
        }
        
        int index=digits[0]-'0';
        for(int i=0;i<str[index].size();i++)
        {
            string val1=val+str[index][i];
            helper(digits.substr(1),val1,ans,str);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        
        string str[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string val="";
        if(digits.size()==0) return ans;
        
        helper(digits,val,ans,str);
        
        return ans;
        
    }
};