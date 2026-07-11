class Solution {
  public:
    void dfs(int n,int m,int d,int& ans,vector<vector<int>>& mat, int xs, int ys, int xd, int yd,vector<vector<bool>>&visited){
        
        if(xs<0||ys<0||xs>=n||ys>=m||mat[xs][ys]==0||visited[xs][ys]) return; 
        if(xs==xd&&ys==yd){
            ans = max(ans,d);
            return;
        }
        visited[xs][ys] = true;
        dfs(n,m,d+1,ans,mat,xs+1,ys,xd,yd,visited);
        dfs(n,m,d+1,ans,mat,xs-1,ys,xd,yd,visited);
        dfs(n,m,d+1,ans,mat,xs,ys+1,xd,yd,visited);
        dfs(n,m,d+1,ans,mat,xs,ys-1,xd,yd,visited);
        visited[xs][ys] = false;
    }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        if(mat[xs][ys]==0||mat[xd][yd]==0) return -1;
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        dfs(n,m,0,ans,mat,xs,ys,xd,yd,visited);
        return ans;
    }
};