class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>ans(n);
        ans[n-1] = -1;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = arr[st.top()];
            st.push(i);
        }
        return ans;
    }
};