// Last updated: 06/07/2026, 18:49:13
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