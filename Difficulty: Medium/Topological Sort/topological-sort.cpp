class Solution {
  public:
  void dfs(int node,stack<int>&st,vector<vector<int>>&adj,vector<int>&visited){
    visited[node] = true;
    for(auto neigh : adj[node]){
        if(!visited[neigh]){
            dfs(neigh,st,adj,visited);
        }
    }
    st.push(node);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
                adj[edges[i][0]].push_back(edges[i][1]);
        }
        stack<int>st;
        vector<int>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,st,adj,visited);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};