// Last updated: 07/09/2026, 22:22:01
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int result = 0;
        for (const int n : nums) result += countDigit(n, digit);
        return result;
    }
    int countDigit(int n, int d){
        int result = 0;
        n = abs(n);
        while (n){
            result += (n % 10) == d;
            n /= 10;
        }
        return result;
    }
};