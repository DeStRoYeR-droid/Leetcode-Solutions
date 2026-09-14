// Last updated: 14/09/2026, 09:20:40
class Solution {
public:
    int numWaterBottles(const int numBottles, const int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};