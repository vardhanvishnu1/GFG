class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>dist(V,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();if(d > dist[node]) continue; 
            for(auto [neigh,neigh_ds] : adj[node]){
                if(dist[neigh]>d+neigh_ds){
                    dist[neigh] = d+neigh_ds;
                    pq.push({d+neigh_ds,neigh});
                }
            }
        }
         for(int i=0;i<V;i++){
                if(dist[i]==INT_MAX) dist[i] = -1;
            }
    return dist;
    }
};