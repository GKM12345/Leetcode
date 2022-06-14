
class Solution {
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n)
    {
        if(i<0 || i==m || j<0 || j==n || grid[i][j]==-1 || grid[i][j]==0)
        {
            return 0;
        }
        grid[i][j]=-1;
        int ans1=dfs(grid,i+1,j,m,n);
        int ans2=dfs(grid,i,j+1,m,n);
        int ans3=dfs(grid,i-1,j,m,n);
        int ans4=dfs(grid,i,j-1,m,n);
        
        return 1+ans1+ans2+ans3+ans4;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int ans1=dfs(grid,i,j,m,n);
                    ans=max(ans,ans1);
                }
            }
        }
        
        return ans;
        
    }
};