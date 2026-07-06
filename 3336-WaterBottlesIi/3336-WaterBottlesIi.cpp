// Last updated: 06/07/2026, 18:53:28
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int result = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange - 1, numExchange++, result++;
        }
        return result;
    }
};