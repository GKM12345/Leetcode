#define mod 1000000007

class Solution {
public:
    int countVowelPermutation(int n) {
        
        map<char,string> mp;
        mp.insert({'a',"e"});mp.insert({'e',"ai"});mp.insert({'i',"aeou"});
        mp.insert({'o',"iu"});mp.insert({'u',"a"});
        
        long long freq[256]={0};
        freq['a']=1,freq['e']=1,freq['i']=1;freq['o']=1;freq['u']=1;
        long long temp[256]={0};
        
        for(int i=2;i<=n;i++)
        {
            for(auto x: mp)
            {
                string str=x.second;
                for(int j=0;j<str.size();j++)
                {
                    temp[str[j]]=(temp[str[j]]+freq[x.first])%mod;
                }
            }
            freq['a']=temp['a'];temp['a']=0;
            freq['e']=temp['e'];temp['e']=0;
            freq['i']=temp['i'];temp['i']=0;
            freq['o']=temp['o'];temp['o']=0;
            freq['u']=temp['u'];temp['u']=0;
        }
        
        int ans=0;
        
        for(int i=97;i<=122;i++)
        {
            ans=(ans+freq[i])%mod;
        }
        
        return ans;
        
        
    }
};