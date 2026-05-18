class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        start = start%1000;
        end = end%1000;
        vector<int>dist(1000,-1);
        queue<int>q;
        q.push(start);
        dist[start] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr==end) return dist[curr];
            for(int i=0;i<n;i++){
                int next = (curr*arr[i])%1000;
                if(dist[next]==-1){
                    dist[next] = dist[curr]+1;
                    q.push(next);
                }
            }
        }
    return -1;
    }
};