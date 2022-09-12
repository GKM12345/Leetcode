class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n=tokens.size();
        int si=0,ei=n-1;
        
        int maxpower=0;
        
        sort(tokens.begin(),tokens.end());
        
        int val=0;
        while(si<=ei)
        {
            if(tokens[si]<=power)
            {
                power=power-tokens[si];
                val+=1;
                si++;
            }
            else if(val>0)
            {
                power=power+tokens[ei];
                val-=1;
                ei--;
            }
            else
            {
                break;
            }
            
            maxpower=max(maxpower,val);
        }
        
        return maxpower;
        
    }
};