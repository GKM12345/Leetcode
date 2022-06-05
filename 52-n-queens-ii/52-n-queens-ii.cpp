class Solution {
    
    bool isSafe(vector<vector<int>> &board, int r, int c, int n)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=r && board[i][c]==1) return false;
        }
        for(int i=0;i<n;i++)
        {
            if(i!=c && board[r][i]==1) return false;
        }
        int row=r-1,col=c-1;
        while(row>=0 && col>=0)
        {
            if(board[row][col]==1) return false;
            row--;
            col--;
        }
        row=r+1,col=c+1;
         while(row<n && col<n)
        {
            if(board[row][col]==1) return false;
              row++;
              col++;
        }
         row=r-1,col=c+1;
         while(row>=0 && col<n)
        {
            if(board[row][col]==1) return false;
              row--;
              col++;
        }
         row=r+1,col=c-1;
         while(row<n && col>=0)
        {
            if(board[row][col]==1) return false;
              row++;
              col--;
        }
        
        return true;
    }
    
    void helper(int n, vector<vector<int>> &board, int &ans, int row)
    {
        if(row==n)
        {
            ans++;
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i,n))
            {
                board[row][i]=1;
                helper(n,board,ans,row+1);
                board[row][i]=0;
            }
        }
    }
    
public:
    int totalNQueens(int n) {
        
        vector<vector<int>> board(n,vector<int>(n,0));
        int ans=0;
        helper(n,board,ans,0);
        return ans;
        
    }
};