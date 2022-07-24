class Solution {
    
    bool found(vector<vector<int>>& matrix, int row, int si, int ei, int target)
    {
        while(si<=ei)
        {
            int mid=(ei+si)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]<target) si=mid+1;
            else ei=mid-1;
        }
        
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(matrix[i][m-1]<target) continue;
           
            bool ans=found(matrix,i,0,m-1,target);
            if(ans==true) return ans;
        }
        
        return false;
        
    }
};