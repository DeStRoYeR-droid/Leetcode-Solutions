// Last updated: 06/07/2026, 19:02:28
class Solution {
public:
    int numWaterBottles(const int numBottles, const int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};