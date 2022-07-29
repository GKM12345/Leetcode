class Solution {
    
    void CompressString(string s,vector<pair<char,int>> &freq1)
    {
        char ch=s[0];
        int count=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==ch)
            {
                count++;
            }
            else
            {
                freq1.push_back({ch,count});
                count=1;
                ch=s[i];
            }
        }
        
        freq1.push_back({ch,count});

    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        int n=words.size();
        vector<string> ans;
        
        vector<pair<char,int>> freq1;
        CompressString(pattern,freq1);
        
        
        
        for(int i=0;i<n;i++)
        {
            vector<pair<char,int>> freq2;
            CompressString(words[i],freq2);
            if(freq1.size()==freq2.size())
            {
                bool isMap=true;
                unordered_map<char,char> mp,mp2;
                for(int i=0;i<freq1.size();i++)
                {
                    if((mp.count(freq1[i].first)==0 || mp[freq1[i].first]==freq2[i].first) && (mp2.count(freq2[i].first)==0 || mp2[freq2[i].first]==freq1[i].first))
                    {
                        if(freq2[i].second!=freq1[i].second)
                        {
                            isMap=false;
                            break;
                        }
                        mp[freq1[i].first]=freq2[i].first;
                        mp2[freq2[i].first]=freq1[i].first;
                    }
                    else
                    {
                        isMap=false;
                        break;
                    }
                }
                
                if(isMap) ans.push_back(words[i]);
            }
        }
        
        return ans;
        
    }
};