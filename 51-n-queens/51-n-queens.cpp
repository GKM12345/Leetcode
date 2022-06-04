class Solution {
    
     bool isSafe(vector<vector<string>>v,int r,int c){
        for(int i=r-1;i>=0;i--){
            if(v[i][c]=="Q") return false;
        }
        for(int i=r-1,j=c-1;j>=0 && i>=0;i--,j--){
            if(v[i][j]=="Q") return false;
        }
        for(int i=r-1,j=c+1;j<v.size() && i>=0;i--,j++){
            if(v[i][j]=="Q") return false;
        }
        return true;
    }
    
    void helper(int n, int row, vector<vector<string>>& board, vector<vector<string>> &ans)
    {
        if(row==n)
        {
            vector<string> val;
            for(int i=0;i<n;i++)
            {
                string s="";
                for(int j=0;j<n;j++)
                {
                    s=s+board[i][j];
                }
                val.push_back(s);
            }
            
            ans.push_back(val);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i))
            {
                board[row][i]="Q";
                helper(n,row+1,board,ans);
                board[row][i]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> val;
        
        vector<vector<string>> board(n,vector<string>(n,"."));
        vector<vector<string>> ans;
        helper(n,0,board,ans);
        return ans;
        
    }
};