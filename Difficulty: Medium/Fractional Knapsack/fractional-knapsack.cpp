class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<val.size();i++){
            double x = (val[i]*1.0)/(wt[i]*1.0);
            pq.push({x,wt[i]});
        }
        double ans =0;
        while(capacity>0&&!pq.empty()){
            auto [curr,weight] = pq.top();
            pq.pop();
            if(capacity>=weight){
                capacity-=weight;
                ans+=curr*weight;
            }
            else{
                ans+=capacity*curr;
                capacity=0;
            }
        }
        return ans;
    }
};
