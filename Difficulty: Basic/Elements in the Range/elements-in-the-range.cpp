class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n = arr.size();
        map<int,int>freq;
        for(int i=start;i<=end;i++) freq[i]++;
        for(int i=0;i<n;i++){
            if(arr[i]>=start&&arr[i]<=end) freq[arr[i]]--;
        }
        for(auto el : freq){
            if(el.second>0) return false;
        }
        return true;
    }
};
