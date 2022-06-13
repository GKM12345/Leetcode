class Solution {
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n)
    {
        if((i==m || j==n || i<0 || j<0) || board[i][j]=='X' || board[i][j]=='#')
        {
            return;
        }
        
        board[i][j]='#';
        dfs(board,i+1,j,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i-1,j,m,n);
        dfs(board,i,j-1,m,n);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O')
                {
                    dfs(board,i,j,m,n);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};