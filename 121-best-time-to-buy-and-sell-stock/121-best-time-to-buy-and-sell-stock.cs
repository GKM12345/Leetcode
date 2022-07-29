public class Solution {
    public int MaxProfit(int[] arr) {
        
        int n=arr.Length;
        
        int[] pmin=new int[n];

        pmin[0]=arr[0];

        for(int i=1;i<n;i++){

            pmin[i]=Math.Min(pmin[i-1],arr[i]);

        }

        

        int ans=0;

        for(int i=0;i<n;i++)

        {

            if(arr[i]-pmin[i]>ans)
            {
                ans=arr[i]-pmin[i];
            }

        }

        

        return ans;
        
    }
}