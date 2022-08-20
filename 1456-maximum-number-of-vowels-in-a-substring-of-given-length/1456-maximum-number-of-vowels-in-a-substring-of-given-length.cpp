class Solution {
public:
    int maxVowels(string s, int k) {
        
        int CountofVowel=0;
        unordered_set<int> st={'a','e','i','o','u'};
        
        for(int i=0;i<k;i++)
        {
            if(st.find(s[i])!=st.end())
            {
                CountofVowel++;
            }
        }
        
        int MaxVowelinK=CountofVowel;
        int i=1,j=k;
        while(j<s.size())
        {
            if(st.find(s[j])!=st.end()) CountofVowel++;
            if(st.find(s[i-1])!=st.end()) CountofVowel--;
            i++;j++;
            
            MaxVowelinK=max(CountofVowel,MaxVowelinK);
        }
        
        return MaxVowelinK;
        
    }
};