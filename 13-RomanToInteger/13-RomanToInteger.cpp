// Last updated: 13/07/2026, 22:30:29
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        char prev = ' ';
        for (char& ch : s){
            if (ch == 'M'){
                result += (prev == 'C') ? 800 : 1000;
            }
            if (ch == 'D'){
                result += (prev == 'C') ? 300 : 500;
            }
            if (ch == 'C'){
                result += (prev == 'X') ? 80 : 100;
            }
            if (ch == 'L'){
                result += (prev == 'X') ? 30 : 50;
            }
            if (ch == 'X'){
                result += (prev == 'I') ? 8 : 10;
            }
            if (ch == 'V'){
                result += (prev == 'I') ? 3 : 5;
            }
            if (ch == 'I'){
                result += 1;
            }
            prev = ch;
        }
        return result;
    }
};