class Solution {
  public:
    int countSubarrays(vector<int> &a) {
        // code here
        int n  = a.size();
        int ans =0;
        stack<int>st;
        for(int i= n-1;i>=0;i--){
            while(!st.empty()&&a[i]<=a[st.top()]) st.pop();
            int last = (st.empty() ? n : st.top());  
            ans += (last - i);
        st.push(i);
        }
        return ans;
    }
};