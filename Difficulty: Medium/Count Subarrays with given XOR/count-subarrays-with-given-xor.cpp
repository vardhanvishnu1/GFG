class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
          long count = 0;
    int current_xor = 0;
    
    // map to store the frequency of prefix XORs
    unordered_map<int, int> freq;
    
    // Base case: a prefix XOR of 0 has occurred once
    freq[0] = 1;
    
    for (int num : arr) {
        // Update prefix XOR for current element
        current_xor ^= num;
        
        // We need: current_xor ^ target = k
        // Which means: target = current_xor ^ k
        int target = current_xor ^ k;
        
        // If target exists in map, add its frequency to count
        if (freq.find(target) != freq.end()) {
            count += freq[target];
        }
        
        // Update the frequency of the current prefix XOR
        freq[current_xor]++;
    }
    
    return count;
    }
};