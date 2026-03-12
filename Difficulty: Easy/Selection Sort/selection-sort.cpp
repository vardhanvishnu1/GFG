class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &a) {
        // code here
        int n = a.size();
        for(int i=0;i<n-1;i++){
            int min_idx = i;
            for(int j = i+1;j<n;j++){
                if(a[min_idx]>a[j]){
                    min_idx=j;
                }
            }
            if(min_idx!=i) swap(a[min_idx],a[i]);
        }
    }
};