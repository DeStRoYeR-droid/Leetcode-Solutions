// Last updated: 13/07/2026, 22:28:41
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n = digits.size();
        reverse(digits.begin(), digits.end());
        int carry = 1, i = 0;
        while (i < n && carry){
            digits[i] += carry;
            if (digits[i] >= 10){
                digits[i] = digits[i] % 10;
                carry = 1;
            }
            else carry = 0;
            ++i;
        }
        if (carry) digits.push_back(1);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};