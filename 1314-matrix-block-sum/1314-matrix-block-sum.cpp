class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                mat[i][j]=mat[i][j]+mat[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                mat[j][i]=mat[j][i]+mat[j-1][i];
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int i1=max(0,i-k);
                int i2=min(m-1,i+k);
                int j1=max(0,j-k);
                int j2=min(n-1,j+k);
                
                ans[i][j]=mat[i2][j2];
                if(j1>0) ans[i][j]-=mat[i2][j1-1];
                if(i1>0) ans[i][j]-=mat[i1-1][j2];
                if(i1>0 && j1>0) ans[i][j]+=mat[i1-1][j1-1];
            }
        }
        
        return ans;
        
    }
};