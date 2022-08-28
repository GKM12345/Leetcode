class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        if(n==1 || m==1) return mat;
        
        
        // sorting 1st half
        for(int i=0;i<n;i++)
        {
            int i1=i,j1=0;
            vector<int> val;
            while(i1<n && j1<m)
            {
                val.push_back(mat[i1][j1]);
                i1++;
                j1++;
            }
            
            sort(val.begin(),val.end());
            i1=i,j1=0;
            int index=0;
            while(i1<n && j1<m)
            {
                mat[i1][j1]=val[index++];
                i1++;
                j1++;
            }
        }
        
        // sorting 2nd half
        
        for(int i=1;i<m;i++)
        {
            int j1=i,i1=0;
            vector<int> val;
            while(i1<n && j1<m)
            {
                val.push_back(mat[i1][j1]);
                i1++;
                j1++;
            }
            
            sort(val.begin(),val.end());
            j1=i,i1=0;
            int index=0;
            while(i1<n && j1<m)
            {
                mat[i1][j1]=val[index++];
                i1++;
                j1++;
            }
        }
        
        return mat;
        
    }
};