class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++) arr[i]%=k;
        map<int,int>mp;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(mp.count(0)) {ans+=mp[0];}
            }
            else{
                if(mp.count(k-arr[i])) {ans+=mp[k-arr[i]];}
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};
// 1 2 2 3 5 7
// 1 2 2 3 1 3 

