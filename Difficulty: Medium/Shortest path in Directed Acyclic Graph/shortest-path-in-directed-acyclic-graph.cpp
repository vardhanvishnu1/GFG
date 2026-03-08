class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
        
        }

        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){

            auto [d,node] = pq.top();
            pq.pop();

            for(auto [neigh,wt] : adj[node]){

                if(dist[neigh] > d + wt){

                    dist[neigh] = d + wt;
                    pq.push({dist[neigh], neigh});

                }
            }
        }

        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};