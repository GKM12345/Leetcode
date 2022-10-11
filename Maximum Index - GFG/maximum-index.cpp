//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool cmp(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.first!=p2.first)
    {
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        // Your code here
        vector<pair<int,int>> arr;
        for(int i=0;i<N;i++)
        {
            arr.push_back({A[i],i});
        }
        
        sort(arr.begin(),arr.end(),cmp);
        
        
        int Maxindex=-1;
        int ans=INT_MIN;
        for(int i=N-1;i>=0;i--)
        {
            Maxindex=max(Maxindex,arr[i].second);
            ans=max(Maxindex-arr[i].second,ans);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends