class Solution {
public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();

        // Correct k
        if ((n & (n - 1)) == 0)
            k /= 2;
        else
            k *= 2;

        if (k >= n) return "-1";

        string st;

        for (char ch : s) {
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }

        // Remove remaining characters from the end
        while (k > 0) {
            st.pop_back();
            k--;
        }

        return st.empty() ? "-1" : st;
    }
};