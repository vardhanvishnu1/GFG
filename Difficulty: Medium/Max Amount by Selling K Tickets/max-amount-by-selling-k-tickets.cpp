class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        long long ans = 0;
        priority_queue<int>pq;
        int n = arr.size();
        for(int i=0;i<n;i++) pq.push(arr[i]);
        while(k>0&&!pq.empty())
        {
            int x = pq.top();
            ans+=pq.top();
            pq.pop();
            x--;
            if(x>0) pq.push(x);
            k--;
        }
        return ans%1000000007;
    }
};