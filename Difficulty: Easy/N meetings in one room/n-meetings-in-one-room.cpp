class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int,int>>timings(n);
        for(int i=0;i<n;i++){
            pair<int,int>pi;
            pi.first = end[i];
            pi.second = start[i];
            timings[i]=(pi);
        }
        sort(timings.begin(),timings.end());
        int ans =1;
        int curr = timings[0].first;
        for(int i=1;i<n;i++){
            if(timings[i].second>curr) {ans++;curr = timings[i].first;}
        }
        return ans;
    }
};