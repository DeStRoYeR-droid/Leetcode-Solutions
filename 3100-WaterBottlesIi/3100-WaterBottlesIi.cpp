// Last updated: 07/09/2026, 22:38:04
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