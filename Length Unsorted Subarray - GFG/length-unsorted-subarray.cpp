//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    // code here
	    int arr2[n];
	    for(int i=0;i<n;i++) arr2[i]=arr[i];
	    sort(arr,arr+n);
	    int s=0,e=n-1;
	    
	    while(s<n)
	    {
	        if(arr[s]!=arr2[s])
	        {
	            break;
	        }
	        s++;
	    }
	    
	    while(e>0)
	    {
	        if(arr[e]!=arr2[e])
	        {
	            break;
	        }
	        e--;
	    }
	    
	    
	    if(e==-1 || s==n)
	    {
	        return {0,0};
	    }
	    
	    return {s,e};
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