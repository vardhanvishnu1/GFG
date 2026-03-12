class Solution {
  public:
    void merge(vector<int>& a,int l,int m,int r){
        int n1 = m-l+1;
        int n2 = r-m;
        int L[n1];
        int R[n2];
        for(int i=0;i<n1;i++) L[i]=a[l+i];
        for(int j=0;j<n2;j++) R[j]=a[m+1+j];
        int i=0;
        int j =0;
        int k = l;
        while(i<n1&&j<n2){
            if(L[i]<R[j]){
                a[k] = L[i];
                i++;
            }
            else{
                  a[k] = R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            a[k] = L[i];
            k++;i++;
        }
        while(i<n1){
            a[k] = R[j];
            k++;j++;
        }
    }
      
    void mergeSort(vector<int>& a, int l, int r) {
        // code here
        int n = a.size();
        if(l>=r) return;
        int m = l + (r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
};