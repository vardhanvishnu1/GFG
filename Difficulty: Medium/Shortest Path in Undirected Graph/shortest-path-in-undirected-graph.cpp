class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(V,-1);
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        vector<bool>visited(V,false);
        visited[src] = true;
        int d =0;
        while(!q.empty()){
            int sz = q.size();
            while(sz>0){
                int curr = q.front();
                q.pop();
                dist[curr] = d;
                for(auto neigh : adj[curr]){
                    if(!visited[neigh]){
                        q.push(neigh);
                        visited[neigh] = true;
                    }
                }
                sz--;
            }
            d++;
        }
        return dist;
    }
};
