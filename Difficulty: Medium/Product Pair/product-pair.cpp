class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        bool zero = false;
        int n = arr.size();
        set<int>s;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zero = true;
                if(target==0) return true;
            }
            if(arr[i]!=0&&target%arr[i]==0){
                int needed = target/arr[i];
                if(s.find(needed)!=s.end()) return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};