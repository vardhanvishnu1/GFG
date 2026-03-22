class Solution {
  public:
  bool solve(const vector<int>& arr, int k, long long maxPages) {
        int studentsRequired = 1;
        long long currentStudentPages = 0;

        for (int i = 0; i < arr.size(); i++) {
            // If adding this book exceeds the limit, assign to the next student
            if (currentStudentPages + arr[i] > maxPages) {
                studentsRequired++;
                currentStudentPages = arr[i];
                
                // If we need more students than we actually have, this limit is invalid
                if (studentsRequired > k) {
                    return false;
                }
            } else {
                currentStudentPages += arr[i]; // Give the book to the current student
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(arr.size()<k) return -1;
        int lo = *max_element(arr.begin(),arr.end());
        int hi = accumulate(arr.begin(),arr.end(),0);
        int mid;
        int ans = -1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(solve(arr,k,mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};