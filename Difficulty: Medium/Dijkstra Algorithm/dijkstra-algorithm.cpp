class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int s = edges[i][0];
            int d = edges[i][1];
            int w = edges[i][2];
            adj[s].push_back({d,w});adj[d].push_back({s,w});
        }
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int curr = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(dist[curr]<d) continue;
            for(auto neigh : adj[curr]){
                int node = neigh.first;
                int w = neigh.second;
                if(dist[node]>d+w){
                    dist[node] = d+w;
                    pq.push({d+w,node});
                }
            }
        }
        return dist;
    }
};