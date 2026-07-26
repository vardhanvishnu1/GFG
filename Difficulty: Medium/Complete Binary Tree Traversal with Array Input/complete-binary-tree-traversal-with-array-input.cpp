class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>ans;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            while(sz--){
                int cur = q.front();
                q.pop();
                temp.push_back(arr[cur]);
                if(2*cur+1<n) q.push(2*cur+1);
                if(2*cur+2<n) q.push(2*cur+2);
            }
            ans.push_back(temp);
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};
