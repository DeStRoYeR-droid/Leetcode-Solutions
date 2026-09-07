// Last updated: 07/09/2026, 22:27:27
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);
        while (n > 0){
            freq[n % 10]++;
            n /= 10;
        }
        int maxFreq = INT_MAX, val = 0;
        for (int i = 0; i < 10; ++i){
            if (freq[i] != 0 && freq[i] < maxFreq){
                val = i;
                maxFreq = freq[i];
            }
        }
        return val;
    }
};