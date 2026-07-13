// Last updated: 13/07/2026, 22:25:22
class Solution {
public:
    string fractionToDecimal(const int& numerator, const int& denominator) {
        if (numerator == 0) return "0";
        string result = "";
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        const long long dividend = llabs((long long) numerator);
        const long long divisor = llabs((long long) denominator);

        result += to_string(dividend / divisor);

        long long remainder = dividend % divisor;

        if (remainder == 0) return result;

        result += ".";
        unordered_map<long long, int> mp;
        while (remainder != 0){
            if (mp.count(remainder)){
                result.insert(mp[remainder], "(");
                result += ")";
                break;
            }

            mp[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / divisor);
            remainder %= divisor;
        }

        return result;
    }
};