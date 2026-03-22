// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        int rans = -1;
        int cnt = 0;
        for(int i=0;i<n;i++){
                int lo = 0;
                int hi = m-1;
                int mid;
                int curs=-1;
                while(lo<=hi){
                    mid = lo + (hi-lo)/2;
                    if(arr[i][mid]==1){
                        curs = mid;
                        hi = mid-1;
                    }
                    else lo = mid+1;
                }
                if(curs!=-1) curs = m-curs;
                if(curs>cnt){
                    rans = i;
                    cnt = curs;
                }
        }
        return rans;
    }
};