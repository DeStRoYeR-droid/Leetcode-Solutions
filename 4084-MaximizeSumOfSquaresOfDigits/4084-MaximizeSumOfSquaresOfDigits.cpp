// Last updated: 06/07/2026, 18:48:15
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string result = "";
        for (int i = 0; i < num; ++i){
            int d = min(9, sum);
            result += '0' + d;
            sum -= d;
        }
        return result;
    }
};