// Last updated: 14/09/2026, 09:22:55
class Solution {
public:
    int numSteps(string s) {
        int count = 0;

        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();
            } else {
                int i = s.size() - 1;

                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }

                if (i < 0) {
                    s = "1" + s;
                } else {
                    s[i] = '1';
                }
            }

            count++;
        }

        return count;
    }
};