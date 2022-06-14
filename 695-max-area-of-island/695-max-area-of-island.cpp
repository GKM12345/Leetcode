
class Solution {
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& seen)
    {
        if(i<0 || i==m || j<0 || j==n || seen[i][j]==1 || grid[i][j]==0)
        {
            return 0;
        }
        seen[i][j]=1;
        int ans1=dfs(grid,i+1,j,m,n,seen);
        int ans2=dfs(grid,i,j+1,m,n,seen);
        int ans3=dfs(grid,i-1,j,m,n,seen);
        int ans4=dfs(grid,i,j-1,m,n,seen);
        
        return 1+ans1+ans2+ans3+ans4;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> seen(m,vector<int>(n,0));
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && seen[i][j]==0)
                {
                    int ans1=dfs(grid,i,j,m,n,seen);
                    ans=max(ans,ans1);
                }
            }
        }
        
        return ans;
        
    }
};