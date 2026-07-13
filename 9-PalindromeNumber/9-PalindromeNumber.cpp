// Last updated: 13/07/2026, 22:30:35
class Solution {
public:
    bool isPalindrome(int& x) {
        if (x < 0) return false;
        int y = x;
        long int rev = 0;
        while (y > 0){
            rev = rev * 10;
            rev += y % 10;
            y = y / 10;
        }
        return rev == x;
    }
};