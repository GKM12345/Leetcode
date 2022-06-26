class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        vector<int> pre(n),suf(n);
        
        pre[0]=cardPoints[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=cardPoints[i]+pre[i-1];
        }
         suf[0]=cardPoints[n-1];
        int j=0;
        for(int i=n-2;i>=0;i--)
        {
            suf[j+1]=cardPoints[i]+suf[j];
            j++;
        }
        
        int Max=0;
        for(int i=0;i<=k;i++)
        {
            int index1=i-1;
            int index2=k-i-1;
            if(index1>=0 && index2<n && index2>=0)
            {
                int val=pre[index1]+suf[index2];
                Max=max(Max,val);
            }
            else if(index1<0)
            {
                Max=max(Max,suf[index2]);
            }
            else if(index2<0)
            {
                Max=max(Max,pre[index1]);
            }
        }
        
        return Max;
        
        
    }
};