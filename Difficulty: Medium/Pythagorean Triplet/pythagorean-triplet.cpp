class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<bool> freq(maxVal + 1, false);

        for(int x : arr)
            freq[x] = true;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                long long sum = 1LL*arr[i]*arr[i] + 1LL*arr[j]*arr[j];
                int c = sqrt(sum);

                if(c*c == sum && c <= maxVal && freq[c])
                    return true;
            }
        }

        return false;
    }
};