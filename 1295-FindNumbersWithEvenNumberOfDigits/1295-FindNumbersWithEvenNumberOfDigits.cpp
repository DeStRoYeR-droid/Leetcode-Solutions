// Last updated: 14/09/2026, 09:25:32
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (const int& num : nums) result += (numDigits(num) % 2 == 0);
        return result;
    }

    inline int numDigits(int n){
        int result = 0;
        while (n > 0){
            ++result;
            n /= 10;
        }
        return result;
    }
};