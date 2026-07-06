// Last updated: 06/07/2026, 18:52:14
class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (const int& n : nums){
            result = min(result, sumDigits(n));
        }
        return result;
    }
    int sumDigits(int n){
        int result = 0; 
        while (n){
            result += n % 10;
            n = n / 10;
        }
        return result;
    }
};