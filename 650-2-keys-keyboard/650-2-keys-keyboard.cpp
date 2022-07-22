class Solution {
public:
  
      int minSteps(int n) {
        
        if(n==1)
        {
            return 0;
        }
     
    int totalStep=INT_MAX;
    for(int i=n/2;i>=1;i--)
    {
        if(n%i==0 && i>1)
        {
            int curr_step=minSteps(i)+1+(n-i)/i;
            totalStep=min(totalStep,curr_step);
        }
        else if(i==1)
        {
            int curr_step=n;
            totalStep=min(totalStep,curr_step);
        }
        
    }
        
    return totalStep;
        
    }
};