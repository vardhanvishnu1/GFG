class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<bool>visited(adj.size(),false);
        vector<int>ans;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
             int curr_node = q.front();q.pop();
                    if(!visited[curr_node]){
                        visited[curr_node] = true;
                        for(int i=0;i<adj[curr_node].size();i++){
                                q.push(adj[curr_node][i]);
                        }
                        ans.push_back(curr_node);
                    }
        }
        return ans;
    }
};