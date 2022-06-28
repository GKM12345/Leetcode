class Solution {
public:
    int minDeletions(string s) {
        
        int arr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            arr[index]++;
        }
        
        set<int> st;
        if(arr[0]>0)
        {
            st.insert(arr[0]);
        }
        
        int ans=0;
        for(int i=1;i<26;i++)
        {
            if(arr[i]>0)
            {
                int val=arr[i];
                if(st.count(val)>0)
                {
                    while(val>0 && st.count(val)>0)
                    {
                        val--;
                        ans++;
                    }
                }
                
                if(val>0)
                    {
                        st.insert(val);
                    }
            }
        }
        
        return ans;
        
    }
};