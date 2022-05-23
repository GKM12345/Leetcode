class Solution {
public:

vector<string> v;//dummy vector
int t[601][101][101];//memoization array

int rec(int k,int m,int n){
    if(k<=0||(m<=0&&n<=0))return 0;//Base Condition.
    if(t[k][m][n]) return t[k][m][n];
    string s=v[k-1];
    int cnt0=0,cnt1=0;//count of 0s and 1s in string.
    for(auto i:s){
        if(i=='0')cnt0++;
        else cnt1++;
    }
    if(cnt0>m||cnt1>n) return t[k][m][n]=rec(k-1,m,n);//recursion call if one or both the parameters are small.
    return t[k][m][n]=max(rec(k-1,m,n),1+rec(k-1,m-cnt0,n-cnt1));//recursion call for finding maximum count.
}
int findMaxForm(vector<string>& strs, int m, int n) {
    v=strs;
    return rec(v.size(),m,n);
}
//Please Upvote if u like the solution\U0001f609\U0001f609\U0001f609
};