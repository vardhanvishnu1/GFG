class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(V,false);
        vector<int>parent(V,-1);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                visited[i] = true;
                while(!q.empty()){
                    int curr_node = q.front();q.pop();
                    for(auto neigh : adj[curr_node]){
                        if(!visited[neigh]){
                            visited[neigh] = true;
                            parent[neigh] = curr_node;
                            q.push(neigh);
                        }
                        else{
                            if(parent[curr_node]!=neigh) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};