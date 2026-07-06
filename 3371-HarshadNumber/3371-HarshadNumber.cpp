// Last updated: 06/07/2026, 18:53:21
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