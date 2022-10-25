//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int i ;
        int ans = 0 ;
        int ans1 = 0 ;
        int *ptr = new int[2];
        for( i = 0 ; i < n ; i++){
            ans = (ans ^ arr[i]);
        }
        for( i = 1 ; i <= n ; i++){
            ans1 = (ans1 ^ i);
        }
        int z = (ans ^ ans1);
        bool got = false;
        long long x = 1;
        long long mask = ( x << 31);
        for(i = 31 ; i >= 0 ; i--){
            if((z & mask)){
                int val1 = 0 ;
                int val2 = 0 ;
                for(int j = 0 ; j < n ; j++){
                    if((arr[j] & mask)){
                        val1 = (val1 ^ arr[j]);
                    }
                    else{
                        val2 = (val2 ^ arr[j]); 
                    }
                }
                for(int j = 1 ; j <= n ; j++){
                    if(j & mask){
                        val1 = (val1 ^ j);
                    }
                    else{
                        val2 = (val2 ^ j);
                    }
                }
                ptr[0] = val1;
                ptr[1] = val2;
                got = true;
                break;
            }
            if(got){
                break;
            }
            mask >>= 1;
        }
        int count = 0 ;
        for( i = 0 ; i < n ; i++){
            if(arr[i] == ptr[0]){
                count++;
            }
        }
        if(count < 2){
            swap(ptr[0] , ptr[1]);
        }
        return ptr;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends