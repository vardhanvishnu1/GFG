class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int t = 0;
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            while(sz>0){
                int ci = q.front().first;
                int cj = q.front().second;
                q.pop();
                mat[ci][cj]=-1;
                for(int i=0;i<4;i++){
                    int ni = ci + dir[i][0];
                    int nj = cj + dir[i][1];
                    if(ni<0||nj<0||ni>=n||nj>=m||mat[ni][nj]==2||mat[ni][nj]==0||mat[ni][nj]==-1) continue;
                    mat[ni][nj]=2;
                    q.push({ni,nj});
                    flag = true;
                }
                sz--;
            }
           if(flag) t++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) return -1;
            }
        }
    return t;
    }
};