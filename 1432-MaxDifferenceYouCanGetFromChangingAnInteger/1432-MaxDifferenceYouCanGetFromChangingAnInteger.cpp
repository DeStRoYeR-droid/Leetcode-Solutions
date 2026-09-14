// Last updated: 14/09/2026, 09:22:37
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        set<char> digits(s.begin(), s.end());

        int maxVal = num, minVal = num;

        for (char digit : digits){
            for (char newDigit = '0'; newDigit <= '9'; ++newDigit){
                if (s[0] == digit && newDigit == '0') continue;
                string newS = s;
                replace(newS.begin(), newS.end(), digit, newDigit);
                int newNum = stoi(newS);

                maxVal = max(newNum, maxVal);
                minVal = min(newNum, minVal);
            }
        }

        return maxVal - minVal;
    }
};