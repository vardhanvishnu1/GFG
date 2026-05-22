class Solution {
  public:
  void dfs(int n,int m,int i,int j,vector<vector<int>>& grid){
      if(i<0||j<0||i>=n||j>=m||grid[i][j]==0) return;
      grid[i][j] =0;
      dfs(n,m,i+1,j,grid);dfs(n,m,i,j+1,grid);dfs(n,m,i-1,j,grid);dfs(n,m,i,j-1,grid);
  }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(n,m,i,0,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1) dfs(n,m,0,i,grid);
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1) dfs(n,m,i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1) dfs(n,m,n-1,i,grid);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};