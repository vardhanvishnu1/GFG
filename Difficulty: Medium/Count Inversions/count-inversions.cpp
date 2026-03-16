class Solution {
  public:
  void merge(int& count,vector<int> &a,int l,int mid,int r){
      int n1 = mid-l+1;
      int n2 = r-mid;
      int L[n1];
      int R[n2];
      for(int i=0;i<n1;i++){
        L[i] = a[l+i];
      }
      for(int i=0;i<n2;i++){
        R[i] = a[mid+i+1];
      }
        int i=0;
        int j =0;
        int k = l;
        while(i<n1&&j<n2){
        if(L[i]<=R[j]){
        a[k] = L[i];
        i++;
        }
        else{
        count+=(n1-i);
        a[k] = R[j];
        j++;
        }
        k++;
        }
        while(i<n1){
        a[k] = L[i];
        k++;i++;
        }
        while(j<n2){
        a[k] = R[j];
        k++;j++;
        }
  }
  void mergeSort(int& count,vector<int> &a,int l,int r){
      int n = a.size();
      if(l<r){
          int mid = l + (r-l)/2;
          mergeSort(count,a,l,mid);
          mergeSort(count,a,mid+1,r);
          merge(count,a,l,mid,r);
      }
  }
    int inversionCount(vector<int> &a) {
        // Code Here
        int n = a.size();
        int count = 0;
        mergeSort(count,a,0,n-1);
        return count;
    }
};