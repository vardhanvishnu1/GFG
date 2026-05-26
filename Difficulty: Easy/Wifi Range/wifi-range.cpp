
class Solution {
  public:
    bool wifiRange(string &s, int x) {

        int n = s.size();

        int coveredTill = -1;

        for(int i = 0; i < n; i++) {

            if(s[i] == '1') {

                int left = max(0, i - x);
                int right = min(n - 1, i + x);

                // gap exists
                if(left > coveredTill + 1)
                    return false;

                coveredTill = max(coveredTill, right);
            }
        }

        return coveredTill == n - 1;
    }
};