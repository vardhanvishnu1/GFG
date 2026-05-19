class Solution {
  public:
  void solve(int n,int m,int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&visited){
      if(i<0||j<0||i>=n||j>=m||grid[i][j]=='W'||visited[i][j]) return;
      visited[i][j] = true;
      solve(n,m,i+1,j,grid,visited);solve(n,m,i-1,j,grid,visited);
      solve(n,m,i,j+1,grid,visited);solve(n,m,i,j-1,grid,visited);
      solve(n,m,i+1,j+1,grid,visited);solve(n,m,i-1,j-1,grid,visited);
      solve(n,m,i-1,j+1,grid,visited);solve(n,m,i+1,j-1,grid,visited);
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='L'){
                    solve(n,m,i,j,grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};