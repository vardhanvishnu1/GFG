class Solution {
  public:
  
   void dfs(vector<int>&temp,int node,vector<vector<int>>& adj,vector<bool>&visited){
        visited[node] = true;
        temp.push_back(node);
        for(auto neigh : adj[node]){
            if(!visited[neigh]){
                dfs(temp,neigh,adj,visited);
            }
        }
    }  
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(V,false);
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>temp;
                dfs(temp,i,adj,visited);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
