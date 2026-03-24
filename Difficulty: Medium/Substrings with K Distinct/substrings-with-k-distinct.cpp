#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Helper to count substrings with AT MOST k distinct characters
    long long solve(string& s, int k) {
        if (k <= 0) return 0;
        
        int n = s.size();
        int l = 0, r = 0;
        long long ans = 0;
        int distinctCount = 0;
        int freq[26] = {0}; // Faster than map

        while (r < n) {
            // If this is a new character in our window
            if (freq[s[r] - 'a'] == 0) {
                distinctCount++;
            }
            freq[s[r] - 'a']++;

            // Shrink window if we have too many distinct characters
            while (distinctCount > k) {
                freq[s[l] - 'a']--;
                if (freq[s[l] - 'a'] == 0) {
                    distinctCount--;
                }
                l++;
            }

            // Standard sliding window count: adds length of current valid window
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

    long long countSubstr(string s, int k) {
        // Exactly(k) = AtMost(k) - AtMost(k-1)
        return solve(s, k) - solve(s, k - 1);
    }
};