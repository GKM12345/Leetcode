class NumMatrix {
    
    vector<vector<int>> arr;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            vector<int> v;
            v.push_back(sum);
            for(int j=0;j<m;j++)
            {
                sum=sum+matrix[i][j];
                v.push_back(sum);
            }
            arr.push_back(v);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum=0;
        for(int i=row1;i<=row2;i++)
        {
            int val=arr[i][col2+1]-arr[i][col1];
            sum+=val;
        }
        
        return sum;
        
        
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */