class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        unordered_map<int,vector<int>>idx;
        for(int i=0;i<n;i++){
            idx[arr[i]].push_back(i);
        }
        int q = queries.size();
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            vector<int>temp = idx[x];
            int left = lower_bound(temp.begin(),temp.end(),l)-temp.begin();
            int right = upper_bound(temp.begin(),temp.end(),r)-temp.begin();
            ans[i] = right-left;
        }
        return ans;
    }
};