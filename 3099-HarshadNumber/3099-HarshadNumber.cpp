// Last updated: 07/09/2026, 22:37:42
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int result = 0, cx = x;
        while (cx){
            result += cx % 10, cx /= 10;
        }
        return (x % result == 0) ? result : -1;
    }
};