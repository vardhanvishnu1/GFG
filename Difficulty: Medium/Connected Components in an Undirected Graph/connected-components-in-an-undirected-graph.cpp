class Solution {
  public:
  
    void dfs(vector<vector<int>>&ans,int node,vector<int>&v,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node] = true;
        v.push_back(node);
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                dfs(ans,neigh,v,adj,visited);
            }
        }
        return;
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>ans;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>v;
                dfs(ans,i,v,adj,visited);
                ans.push_back(v);
            }
        }
        return ans;
    }
};
