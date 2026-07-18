class Solution {
  public:
  bool dfs(int parent,int node,vector<vector<int>>&adj,vector<bool>&visited){
      visited[node] = true;
      for(auto neigh : adj[node]){
          if(neigh==parent) continue;
          if(visited[neigh]) return true;
          if(!visited[neigh]){
            if(dfs(node,neigh,adj,visited)) return true;
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(-1,i,adj,visited)) return true;
            }
        }
        return false;
    }
};