class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int n=data.size();
        vector<string> v(n);
        
        for(int i=0;i<n;i++)
        {
            v[i]=bitset<8>(data[i]).to_string();
            // cout << v[i] << " ";
        }
        
        int i=0;
        while(i<n)
        {
            if(v[i].substr(0,5)=="11110")
            {
                if(i+3>=n)
                {
                    return false;
                }
                i++;
                if(v[i].substr(0,2)=="10")
                {
                    i++;
                }
                else return false;
                if(v[i].substr(0,2)=="10")
                {
                    i++;
                }
                else return false;
                if(v[i].substr(0,2)=="10")
                {
                    i++;
                }
                else return false;
                
            }
            else if(v[i].substr(0,4)=="1110")
            {
                if(i+2>=n)
                {
                    return false;
                }
                i++;
                if(v[i].substr(0,2)=="10")
                {
                    i++;
                }
                else return false;
                if(v[i].substr(0,2)=="10")
                {
                    i++;
                }
                else return false;
            }
            else if(v[i].substr(0,3)=="110")
            {
                if(i+1>=n)
                {
                    return false;
                }
                i++;
                if(v[i].substr(0,2)=="10")
                {
                    i++;
                }
                else return false;
            }
            else if(v[i].substr(0,1)=="0")
            {
                i++;
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
};