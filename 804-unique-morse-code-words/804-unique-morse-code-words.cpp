class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        int n=words.size();
        
        string temp[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<words[i].size();j++)
            {
                s=s+(temp[words[i][j]-'a']);
            }
            
            st.insert(s);
        }
        
        return st.size();
        
    }
};