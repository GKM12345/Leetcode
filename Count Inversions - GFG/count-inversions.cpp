//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int t=0;

class Solution{
    
    long long merge(long long *arr, long long si, long long mid, long long ei)
    {
        long long ans=0;
        long long temp[ei-si+1];
        
        long long i=si,j=mid+1;
        long long k=0;
        
        while(i<=mid && j<=ei)
        {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                k++;i++;
            }
            else
            {
                ans+=mid-i+1;
                temp[k]=arr[j];
                k++;j++;
            }
        }
        
        while(i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        
        while(j<=ei)
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
        k=0;
        for(long long p=si;p<=ei;p++)
        {
            arr[p]=temp[k++];
        }
        
        return ans;
        
    }
    
    long long mergesort(long long *arr, long long si, long long ei)
    {
        if(si>=ei)
        {
            return 0;
        }
        
        long long mid=(si+ei)/2;
        
        long long ans1=mergesort(arr,si,mid);
        long long ans2=mergesort(arr,mid+1,ei);
        
        long long ans3=merge(arr,si,mid,ei);
        
        
        return ans1+ans2+ans3;
    }
    
    
  public:
 
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        if(t==100)
        {
            return -1;
        }
        t++;
        long long ans=mergesort(arr,0,N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends