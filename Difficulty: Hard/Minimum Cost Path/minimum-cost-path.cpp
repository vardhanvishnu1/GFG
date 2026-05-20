

class Solution {
  public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > q;
        dist[0][0] = grid[0][0];
        q.push({grid[0][0],{0,0}});
        vector<vector<int>>d = {{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int cost = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                if(grid[nx][ny]+cost<dist[nx][ny]){
                    dist[nx][ny] = grid[nx][ny]+cost;
                    q.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};