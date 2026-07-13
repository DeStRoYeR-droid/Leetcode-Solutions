// Last updated: 13/07/2026, 22:19:56
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        const int n = num1.size(), m = num2.size();

        string result = "";
        int index, carry = 0;
        for (index = 0; index < min(n, m); ++index){
            int value = (num1[index] - '0') + (num2[index] - '0') + carry;
            if (value >= 10){
                carry = 1;
                value -= 10;
            }
            else carry = 0;

            result += (char) value + '0';
        }

        while (index < n){
            int value = (num1[index] - '0') + carry;
            if (value >= 10){
                carry = 1;
                value -= 10;
            }
            else carry = 0;

            result += (char) value + '0';
            ++index;
        }

        while (index < m){
            int value = (num2[index] - '0') + carry;
            if (value >= 10){
                carry = 1;
                value -= 10;
            }
            else carry = 0;

            result += (char) value + '0';
            ++index;
        }

        if (carry) result += (char) carry + '0';

        reverse(result.begin(), result.end());
        return result;
    }
};