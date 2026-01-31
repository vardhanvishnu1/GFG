class Solution {
  public:
    void solve(int node,vector<vector<int>>& adj,vector<int>&ans,vector<bool>&visited){
      visited[node] = true;
      for(auto neigh : adj[node]){
          if(!visited[neigh]){
              ans.push_back(neigh);
              solve(neigh,adj,ans,visited);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool>visited(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans.push_back(i);
                solve(i,adj,ans,visited);
            }
        }
        return ans;
    }
};