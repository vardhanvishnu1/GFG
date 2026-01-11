class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
       int n = arr.size();
       sort(arr.begin(),arr.end());
       sort(dep.begin(),dep.end());
       int i=0,j=0;
       int count =0;
       int ans = 1;
       while(i<n&&j<n){
           if(arr[i]<=dep[j]){
               count++;
               i++;
           }
           else{
               count--;
               j++;
           }
           ans = max(ans,count);
       }
       return ans;
    }
};
