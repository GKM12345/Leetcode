//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    
	    int si=0,ei=n-1;
	    int Max=arr[si];
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]<Max)
	        {
	            si=i;
	        }
	        Max=max(Max,arr[i]);
	    }
	    int Min=arr[n-1];
	    for(int i=n-2;i>=0;i--)
	    {
	        if(arr[i]>Min)
	        {
	            ei=i;
	        }
	        Min=min(Min,arr[i]);
	    }
	    
	    if(si==0 && ei==n-1)
	    {
	        return {0,0};
	    }
	    
	    return {ei,si};
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends