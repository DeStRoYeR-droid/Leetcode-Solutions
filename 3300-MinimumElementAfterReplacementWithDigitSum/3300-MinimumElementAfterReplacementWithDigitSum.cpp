// Last updated: 07/09/2026, 22:35:00
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