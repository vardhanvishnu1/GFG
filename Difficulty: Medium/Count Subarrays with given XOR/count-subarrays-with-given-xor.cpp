class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        long ans = 0;
        map<int,int>freq;
        freq[0] = 1;
        int cur = 0;
        for(int i=0;i<n;i++){
            cur^=arr[i];
            if(freq.count(k^cur)) ans+=freq[k^cur];
            freq[cur]++;
        }
        return ans;
    }
};