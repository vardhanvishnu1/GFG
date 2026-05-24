class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int i=0;int j = arr.size()-1;
        while(i!=j){
            if(arr[j]>arr[i]) j--;
            else i++;
        }
        return arr[i];
    }
};