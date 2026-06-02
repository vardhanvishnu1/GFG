class Solution {
public:
    long long findMaxProduct(vector<int>& arr) {
        const long long MOD = 1000000007;

        int neg = 0, zero = 0;
        long long mxNeg = LLONG_MIN;

        for (int x : arr) {
            if (x == 0) zero++;
            else if (x < 0) {
                neg++;
                mxNeg = max(mxNeg, (long long)x);
            }
        }

        int n = arr.size();

        if (zero == n) return 0;

        if (neg == 1 && neg + zero == n) {
            if (zero > 0) return 0;
            return mxNeg;
        }

        long long ans = 1;
        bool skipped = false;

        for (int x : arr) {
            if (x == 0) continue;

            if ((neg & 1) && x == mxNeg && !skipped) {
                skipped = true;
                continue;
            }

            long long cur = (x % MOD + MOD) % MOD;
            ans = (ans * cur) % MOD;
        }

        return ans;
    }
};