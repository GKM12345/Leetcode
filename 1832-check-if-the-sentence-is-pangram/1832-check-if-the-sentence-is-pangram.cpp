class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int> freq(26,0);
        int n=sentence.size();
        
        for(int i=0;i<n;i++)
        {
            freq[sentence[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]<1)
            {
                return false;
            }
        }
        
        return true;
        
    }
};