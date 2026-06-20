class Solution {
public:
    int getLastDigit(string& a, string& b) {

        if (b == "0") return 1;

        int x = 0;
        for(char c : b){
            x = (x * 10 + (c - '0')) % 4;
        }

        if(x == 0) x = 4;

        int y = a.back() - '0';

        int ans = 1;
        for(int i = 0; i < x; i++)
            ans = (ans * y) % 10;

        return ans;
    }
};