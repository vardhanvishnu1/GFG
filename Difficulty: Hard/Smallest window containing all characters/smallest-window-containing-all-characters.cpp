// class Solution {
//   public:
//     string minWindow(string &s, string &p) {
//         // code here
//         int l = 0;
//         int r = 0;
//         set<char>search;
//         int n = p.size();
//         int m = s.size();
//         for(int i=0;i<n;i++) search.insert(p[i]);
//         map<char,int>freq;
//         map<char,int>orgFreq;
//         for(int i=0;i<n;i++) orgFreq[p[i]]++;
//         int st = -1;
//         int end =-1;
//         int cnt =0;
//         while(r<m){
//             if(search.find(s[r])!=search.end()) {freq[s[r]]++;if(freq[s[r]]==orgFreq[s[r]]) cnt++;}
//             while(l<=r&&freq[s[l]]>orgFreq[s[l]]){
//                 freq[s[l]]--;
//                 l++;
//             }
//             if(cnt==search.size()){
//                 while(search.find(s[l])==search.end()){
//                     l++;
//                 }
//                 if(st==-1){
//                     st = l;end = r;
//                 }
//                 else{
//                     if(end-st>r-l){
//                         st = l;end = r;
//                     }
//                 }
//             }
//             r++;
//         }
//         if(st==-1) return "";
//         return s.substr(st,end-st+1);
//     }
// };




#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

class Solution {
public:
    string minWindow(string &s, string &p) {
        int m = s.size();
        int n = p.size();
        if (n > m) return "";

        map<char, int> orgFreq;
        for (char c : p) orgFreq[c]++;
        
        // Number of unique characters in p that must be satisfied
        int required = orgFreq.size();
        
        map<char, int> freq;
        int l = 0, r = 0;
        int cnt = 0; // Tracks how many unique characters meet the required frequency
        
        int st = -1, minLen = m + 1;

        while (r < m) {
            char c = s[r];
            if (orgFreq.count(c)) {
                freq[c]++;
                if (freq[c] == orgFreq[c]) {
                    cnt++;
                }
            }

            // Try to shrink the window when all characters are found
            while (cnt == required) {
                // Update the best result if this window is smaller
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    st = l;
                }

                char leftChar = s[l];
                if (orgFreq.count(leftChar)) {
                    if (freq[leftChar] == orgFreq[leftChar]) {
                        cnt--;
                    }
                    freq[leftChar]--;
                }
                l++;
            }
            r++;
        }

        if (st == -1) return "";
        return s.substr(st, minLen);
    }
};