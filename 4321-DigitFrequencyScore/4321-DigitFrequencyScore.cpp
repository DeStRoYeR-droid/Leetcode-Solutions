// Last updated: 06/07/2026, 18:46:53
class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10, 0);
        while (n){
            freq[n % 10]++;
            n /= 10;
        }

        int result = 0;
        for (int i = 0; i <= 9; ++i){
            result += i * freq[i];
        }
        return result;
    }
};